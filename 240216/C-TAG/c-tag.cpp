#include <iostream>
#include <unordered_set>
using namespace std;

#define MAX_N 500

// 변수 선언
int n, m;
int ans;
string A[MAX_N], B[MAX_N];
unordered_set<string> s;

bool TestLocation(int x, int y, int z)
{
    s.clear();
    // A의 원소를 전부 HashSet에 넣어줌
    for (int i = 0; i < n; i++)
        s.insert(A[i].substr(x, 1) + A[i].substr(y, 1) + A[i].substr(z, 1));

    for (int i = 0; i < n; i++)
        if (s.find(B[i].substr(x, 1) + B[i].substr(y, 1) + B[i].substr(z, 1)) != s.end())
            return false;

    return true;
}

int main()
{
    // input
    // freopen_s(new FILE*, "input.txt", "r", stdin);
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> A[i];
    for (int i = 0; i < n; i++)
        cin >> B[i];

    // solve
    // 서로 다른 세 자리의 조합을 모두 순회
    for (int i = 0; i < m; i++)
        for (int j = i + 1; j < m; j++)
            for (int k = j + 1; k < m; k++)
                // i,j,k 번째 자리 선택 시 두 그룹을 완벽하게 구분할 수 있는지 확인
                if (TestLocation(i, j, k)) ans++;

    // output
    cout << ans;
    return (0);
}