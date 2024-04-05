#include <iostream>
#include <set>

using namespace std;

int N, M;

int main() {
    set<pair<int, int>> s;

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int first, second;
        cin >> first >> second;
        s.insert(make_pair(first, second));
    }
    for (int i = 0; i < M; i++) {
        int num;
        cin >> num;
        if (s.upper_bound(make_pair(num, 0)) != s.end())
        {
            cout << s.upper_bound(make_pair(num, 0))->first << ' ' 
                << s.upper_bound(make_pair(num, 0))->second << '\n';
            s.erase(*s.upper_bound(make_pair(num, 0)));
        }
        else
            cout << -1 << ' ' << -1 << '\n';
    }
    return 0;
}

// 시간복잡도: logN(insert) + logM(find, delete) +