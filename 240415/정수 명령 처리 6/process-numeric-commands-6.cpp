#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> pq;

int N;

int main() {
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        string cmd;
        int num;
        cin >> cmd;
        if (cmd == "push")
        {
            cin >> num;
            pq.push(num);
        }
        else if (cmd == "pop")
        {
            cout << pq.top() << '\n';
            pq.pop();
        }
        else if (cmd == "size")
            cout << pq.size() << '\n';
        else if (cmd == "empty")
            cout << pq.empty() << '\n';
        else if (cmd == "top")
            cout << pq.top() << '\n';
        else
            cout << "\nCMD ERROR\n";
    }

    return 0;
}