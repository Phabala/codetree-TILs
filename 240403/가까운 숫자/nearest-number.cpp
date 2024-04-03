#include <iostream>
#include <set>

using namespace std;

int N;

int main() {
    set<int> s;
    int MIN = 21e8;

    cin >> N;
    s.insert(0);
    for (int i = 0; i < N; i++) {
        int num;
        set<int>::iterator before;
        set<int>::iterator after;
        set<int>::iterator here;
        set<int>::iterator rbeg;

        cin >> num;
        s.insert(num);
        here = s.find(num);
        before = --here;
        here++;
        after = ++here;
        --here;
        rbeg = --(s.end());
        if ((num - *before) < MIN)
            MIN = num - *before;
        if (here != rbeg && (*after - num) < MIN)
            MIN = *after - num;
        cout << MIN << '\n';
    }

    
    return 0;
}