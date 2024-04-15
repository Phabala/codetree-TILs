#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> pq;

int N;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        pq.push(num);
    }

    while (pq.size() > 1)
    {
        int bigger, smaller;
        bigger = pq.top();
        pq.pop();
        smaller = pq.top();
        pq.pop();
        if (bigger != smaller)
            pq.push(bigger - smaller);
    }
    if (pq.empty())
        cout << -1;
    else
        cout << pq.top();
    return 0;
}