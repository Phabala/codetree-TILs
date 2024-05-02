#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int T;
int N;

int main() {
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        v.clear();
        cin >> N;
        for (int i = 1; i <= N; i++) {
            int num;
            cin >> num;
            v.push_back(num);
            if (i % 2 == 1) {
                sort(v.begin(), v.end());
                cout << v[i / 2] << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}