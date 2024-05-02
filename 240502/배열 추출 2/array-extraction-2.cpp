#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq; // 값, sign

int main() {
    cin >> N;
    int num;
    for (int i = 0; i < N; i++) {
        cin >> num;
        if (num == 0)
        {
            if (pq.empty())
                cout << 0 << '\n';
            else
            {
                cout << pq.top().first * pq.top().second << '\n';
                pq.pop();
            }
        }
        else
        {
            if (num < 0)
                pq.push(make_pair(-num, -1));
            else
                pq.push(make_pair(num, 1));
        }
    }
    return 0;
}