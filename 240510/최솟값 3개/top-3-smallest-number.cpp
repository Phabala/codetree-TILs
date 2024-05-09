#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;

priority_queue<int, vector<int>, greater<int> > pq;

int main() {
    cin >> N;
    int num;
    for (int i = 1; i <= N; i++) {
        cin >> num;
        pq.push(num);
        if (i < 3)
            cout << -1 << '\n';
        else
        {
            int a, b;
            a = pq.top();
            pq.pop();
            b = pq.top();
            pq.pop();
            cout << a * b * pq.top() << '\n';
            pq.push(b);
            pq.push(a);
        }
    }

    return 0;
}