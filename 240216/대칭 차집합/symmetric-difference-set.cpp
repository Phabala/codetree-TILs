#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

unordered_set<int> A;
unordered_set<int> B;
vector<int> v;

int main() {
    int num1, num2;
    cin >> num1 >> num2;

    int tmp;
    for (int i = 0; i < num1; i++)
    {
        cin >> tmp;
        A.insert(tmp);
        v.push_back(tmp);
    }
    for (int i = 0; i < num2; i++)
    {
        cin >> tmp;
        B.insert(tmp);
    }
    for (int i = 0; i < v.size(); i++)
    {
        if (B.find(v[i]) != B.end())
        {
            A.erase(v[i]);
            B.erase(v[i]);
        }
    }

    cout << A.size() + B.size();

    return 0;
}