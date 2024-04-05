#include <iostream>
#include <set>

using namespace std;

int N, M;

int main() {
    string cmd;
    set<pair<int, int>> s; // <level, index>

    cin >> N;
    for (int i = 0; i < N; i++) {
        int index, level;
        cin >> index >> level;
        s.insert(make_pair(level, index));
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        int cmd1, cmd2;
        cin >> cmd;
        if (cmd == "ad")
        {
            cin >> cmd1 >> cmd2; // index, level
            s.insert(make_pair(cmd2, cmd1));
        }
        else if (cmd == "sv")
        {
            cin >> cmd1 >> cmd2; // index, level
            s.erase(make_pair(cmd2, cmd1));
        }
        else if (cmd == "rc")
        {
            cin >> cmd1;
            if (cmd1 == 1)
                cout << s.rbegin()->second << '\n';
            else
                cout << s.begin()->second << '\n';
        }
    }

    return 0;
}