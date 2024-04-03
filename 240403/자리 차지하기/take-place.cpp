#include <iostream>
#include <set>

using namespace std;

int N, M;

int main() {
    set<int> s;

    cin >> N >> M;
    for (int i = 1; i <= M; i++)
        s.insert(-i);
    for (int i = 0; i < N; i++) {
        int num;

        cin >> num;
        if (s.lower_bound(-num) != s.end())
            s.erase(*s.lower_bound(-num));
    }

    cout << M - s.size();
    return 0;
}