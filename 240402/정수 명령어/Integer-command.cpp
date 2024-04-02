#include <iostream>
#include <set>

using namespace std;

int T, K;

set<int> s;

int main() {
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        // reset
        s.clear();

        // input
        cin >> K;
        // solve
        char cmd;
        int num;

        for (int i = 0; i < K; i++) {
            cin >> cmd >> num;
            if (cmd == 'I')
                s.insert(num);
            else if (s.begin() != s.end() && cmd == 'D' && num == -1)
                s.erase(*s.begin());
            else if (s.begin() != s.end() && cmd == 'D' && num == 1)
                s.erase(*s.rbegin());
            else if (s.begin() == s.end())
                continue;
            else
                cout << "solve cmd error!!\n";
        }
        
        // output
        if (s.begin() == s.end())
            cout << "EMPTY\n";
        else
            cout << *s.rbegin() << ' ' << *s.begin() << '\n';
    }
    return 0;
}