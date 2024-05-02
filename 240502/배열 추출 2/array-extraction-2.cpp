#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;
priority_queue<pair<int, int>> pq; // 값, isNegative

int main() {
    cin >> N;
    int num;
    for (int i = 0; i < N; i++) {
        cin >> num;
        if (num == 0)
        {
            if (pq.empty())
                cout << 0 << '\n';
            else if (pq.top().second == 0)
            {
                cout << pq.top().first << '\n';
                pq.pop();
            }
            else
            {
                cout << pq.top().first * -1 << '\n';
                pq.pop();
            }
        }
        else
        {
            if (num < 0)
                pq.push(make_pair(-num, 1));
            else
                pq.push(make_pair(num, 0));
        }
    }
    return 0;
}