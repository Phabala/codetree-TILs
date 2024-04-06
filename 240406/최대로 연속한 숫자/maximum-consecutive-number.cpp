#include <iostream>
#include <set>
#include <tuple>

using namespace std;

int n, m;
set<int> s_num;
set<tuple<int, int, int>> s_len; // (-길이, 시작 숫자, 끝 숫자)
// 나는 전체적으로 몇개의 길이가 있는지만 셌는데 여기서 아이디어가 갈렸다.
// 그리고 나는 아직 튜플을 쓸 줄 모른다.

int main()
{
    cin >> n >> m;

    // s_num: 지워진 숫자 모음
    s_num.insert(-1);
    s_num.insert(n + 1);
    // 길이가 긴 구간부터 나오도록 구간의 길이에 -를 붙여서 넣어준다.
    s_len.insert(make_tuple(-(n + 1), -1, n + 1));

    for (int i = 0; i < m; i++) {
        // 숫자를 입력받는다.
        int y;
        cin >> y;

        // 입력받은 숫자를 treeset에 추가한다.
        s_num.insert(y);

        // 입력받은 숫자 y 를 기준으로
        // 그 바로 뒤의 숫자를 z, 바로 앞의 숫자를 x라고 한다.
        set<int>::iterator it;
        it = s_num.find(y);
        it++;
        int z= *it;

        it = s_num.find(y);
        it--;
        int x = *it;

        // 구간의 길이는 (x ~ z) 구간이 사라지며, 
        // (x ~ y) 구간과 (y ~ z) 구간이 새로 생겨난다.
        s_len.erase(make_tuple(
            -(z-x-1), x, z
        ));
        s_len.insert(make_tuple(
            -(y-x-1), x, y
        ));
        s_len.insert(make_tuple(
            -(z-y-1), y, z
        ));

        // y가 추가된 후로 구간 중 가장 긴 구간을 찾아 출력한다.
        int best_length;
        tie(best_length, ignore, ignore) = *s_len.begin();
        cout << -best_length << endl;
    }
}

/*
남아있는 수들은 최대 n개(10^9)가 되어 너무 많기 때문에 지워진 수들을 관리하며 해결합니다.
지워진 수들을 이용하면 (인접한 두 지워진 수들간의 차 -1)이 연속한 남아 있는 수들의 개수가
됩니다. 인접한 수들을 빠르게 찾기 위해 TreeSet을 이용합니다.
-> 이거는 내가 생각한 아이디어와 똑같다.

또한 매 순간마다 가장 큰 구간을 찾고-> 모든 it를 순환하면서?
새롭게 지워진 수를 기점으로 양쪽 구간을 새로 추가해주고 기존 구간을 지우는 것을 빠르게
해결해야 하므로 (구간의 길이, 시작 값, 끝 값) 이렇게 3개의 정보를 원소로 하는 TreeSet을
하나 더 관리합니다.

m개의 수들에 대해 TreeSet을 계속 이용해야 하므로 총 시간복잡도는 O(MlogM)이 됩니다.
-> tuple 을 써야하네 (구간의 길이, 시작 값, 끝 값) 얘를 어떻게 관리한다는거지?

*/