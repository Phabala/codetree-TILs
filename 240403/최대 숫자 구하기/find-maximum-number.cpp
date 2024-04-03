#include <iostream>
#include <set>

using namespace std;

int main() {
    int N, M;
    set<int> s;

    cin >> N >> M;
    for (int i = 1; i <= M; i++)
        s.insert(i);

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        s.erase(num);
        cout << *s.rbegin() << '\n';
    }
        
    
    

    return 0;
}


// set을 이용하는 이유: erase에 logN, 매번 최대값 찾는데 logN 이 걸린다.