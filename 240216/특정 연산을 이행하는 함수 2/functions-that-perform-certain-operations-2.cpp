#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<double> v;

int main() {
    double a, b, c;
    cin >> a >> b >> c;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    sort(v.begin(), v.end());
    cout << ceil(v[2]) << ' ' << floor(v[0]) << ' ' << round(v[1]);
    return 0;
}