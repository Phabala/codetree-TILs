#include <iostream>
#include <set>

using namespace std;

int n, m;
set<int> s;

int main() {
    cin >> n >> m;

    int tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        s.insert(-tmp);
    }

    int num;
    for (int i = 0; i < m; i++) {
        cin >> tmp;
        if (s.lower_bound(-tmp) != s.end())
        {
            num = -1 * *s.lower_bound(-tmp);
            s.erase(-num);
        }
        else
            num = -1;
        cout << num << '\n';
    }
    return 0;
}