#include <iostream>
#include <set>

using namespace std;

int N, K;

int main() {
    set<int> s;
    std::set<int>::iterator it;

    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        s.insert(num);
    }

    it = s.end();
    for (int i = 0; i < K; i++) 
        cout << *(--it) << ' ';
        
    return 0;
}