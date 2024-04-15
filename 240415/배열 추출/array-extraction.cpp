#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> pq;

int N;

int main() {
    cin >> N;

    int num;
    int top;
    for (int i = 0; i < N; i++) {
        cin >> num;
        if (num == 0)
        {
            if (pq.empty())
                cout << 0 << '\n';
            else
            {
                cout << pq.top() << '\n';
                pq.pop();    
            }
        }
        else
            pq.push(num);
    }
    return 0;
}