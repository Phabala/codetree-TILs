#include <iostream>
#include <unordered_set>
using namespace std;

int N; // 1 ~ 100,000
int G; // 2 ~ 250,000
int flag;
unordered_set<int> s;

void    one_group()
{
    int num;
    int first;
    int cnt = 0;
    int candidate;

    cin >> num;
    for (int i = 0; i < num; i++)
    {
        int tmp;
        cin >> tmp;
        if (!flag)
        {
            s.insert(tmp);
            flag = 1;
        }
        if (s.find(tmp) == s.end())
            candidate = tmp;
        else
            cnt++;
    }
    if (cnt == num - 1)
        s.insert(candidate);
}

int main() {
    // input
    // freopen_s(new FILE*, "input.txt", "r", stdin);
    cin >> N >> G;

    // solve
    for (int g = 0; g < G; g++)
        one_group();

    // output
    cout << s.size();
    return 0;
}