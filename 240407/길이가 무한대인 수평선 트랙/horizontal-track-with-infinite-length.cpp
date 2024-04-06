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

/**
0에 가까이 위치해 있는 한명을 A라고 하고 그 뒤에 있는 사람들을 B, C, D... 라고 했을 때
B, C, D 중에서 A의 (위치+속력) 값보다 (위치+속력) 값이 작거나 같 사람들은 1분 뒤에 한 그룹이 된다.

if (A.speed > B.speed) -> if (A.speed - B.speed) * T >= B.position - A.position
-> 한 그룹이 됨 (A를 지움)
*/