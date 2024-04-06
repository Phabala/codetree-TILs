#include <iostream>
#include <set>

using namespace std;

typedef unsigned long long ull;

int N, T;
set<pair<ull, ull>> s; // 위치, 속력

int main() {
    // freopen_s(new FILE*, "input.txt", "r", stdin);
    cin >> N >> T;

    ull position, speed;
    for (int i = 0; i < N; i++) {
        cin >> position >> speed;
        s.insert(make_pair(position, speed));
    }

    set<pair<ull, ull>>::iterator it;
    int bef, aft;
    bef = -21e8;
    aft = 0;
    while (bef != aft) {
        it = s.begin();
        while (true) {
            pair<ull, ull> pre, suf;
            pre = *(it++);
            if (it == s.end())
                break;
            suf = *it;
            if (pre.first + pre.second * T >= suf.first + suf.second * T) {
                s.erase(pre);
                it = s.find(suf);
            }
        }
        bef = aft;
        aft = s.size();
    }
    
    cout << aft;
    return 0;
}