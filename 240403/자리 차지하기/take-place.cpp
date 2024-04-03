#include <iostream>
#include <set>

using namespace std;

int N, M;

int main() {
    set<int> s;

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        s.insert(num);
    }

    cout << s.size();
    return 0;
}