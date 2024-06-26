#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int N, M;

int main() {
    set<int> pos_s;
    set<int> neg_s;
    int MIN;

    cin >> N >> M;
    MIN = 21e8;
    for (int i = 0; i < N; i++) {
        int num;

        cin >> num;
        pos_s.insert(num);
        neg_s.insert(-num);
        if (pos_s.lower_bound(num + M) != pos_s.end())
            MIN = min(MIN, *pos_s.lower_bound(num + M) - num);
        if (neg_s.lower_bound(-num + M) != neg_s.end())
            MIN = min(MIN, *neg_s.lower_bound(-num + M) + num);
    }

    if (MIN == 21e8)
        cout << -1;
    else
        cout << MIN;
    return 0;
}