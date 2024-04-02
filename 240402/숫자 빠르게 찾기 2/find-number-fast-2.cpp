#include <iostream>
#include <set>

using namespace std;

int N, M;
set<int> s;

int main() {
    // input
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        s.insert(num);
    }

    // solve
    for (int i = 0; i < M; i++) {
        int num;
        cin >> num;
        if (s.lower_bound(num) != s.end()) {
            cout << *s.lower_bound(num) << '\n';
        }
        else
            cout << -1 << '\n';
    }
    return 0;
}