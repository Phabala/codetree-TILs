#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int N;

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        if (num > 0)
            pq.push(num);
        else
        {
            if (pq.empty())
                cout << 0 << '\n';
            else
            {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
    }

    return 0;
}