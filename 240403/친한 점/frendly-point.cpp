#include <iostream>
#include <set>

using namespace std;

int N, M; // 점 개수, 질의 개수

int main() {
    set<pair<int, int>> s;

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        s.insert(make_pair(x, y));
    }

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        if (s.upper_bound(make_pair(x, y)) == s.end()) 
            cout << -1 << ' ' << -1 << '\n';
        else
            cout << (*s.upper_bound(make_pair(x, y))).first << ' ' 
            << (*s.upper_bound(make_pair(x, y))).second << '\n';
    }
    return 0;
}

/**
 * height 우선, weight 2nd
 * 
*/