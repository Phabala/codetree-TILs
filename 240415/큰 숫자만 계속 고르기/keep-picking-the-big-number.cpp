#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> pq;

int N, M;

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        int num; cin >> num;
        pq.push(num);
    }
    for (int i = 0; i < M; i++) {
        int top = pq.top();
        pq.pop();
        pq.push(top - 1);
    }
    cout << pq.top();
    return 0;
}