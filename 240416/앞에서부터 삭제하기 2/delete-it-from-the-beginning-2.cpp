#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

vector<int> v; // 순서 저장용
priority_queue<int, vector<int>, greater<int> > pq; // 최소값 O(logN)으로 찾기용
unordered_map<int, int> um; // 값, 개수
/* 일단은 시간초과인 상태로 마무리 */
int N;

int main() {
    // freopen_s(new FILE*, "input.txt", "r", stdin);
    cin >> N;
    int num;
    int sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> num;
        sum += num;
        v.push_back(num);
        pq.push(num);
        if (um.find(num) != um.end())
            um[num]++;
        else
            um[num] = 1;
    }
    double MAX = -1;
    while (v.size() > 2)
    {
        int first = *(v.begin());
        sum -= first;
        v.erase(v.begin());
        um[first]--;
        if (um[first] == 0)
            um.erase(first);
        int smallest = pq.top();
        while (um.find(smallest) == um.end())
        {
            pq.pop();
            smallest = pq.top();
        }
        double now_mean = (sum - smallest) / (v.size() - 1);
        if (now_mean > MAX)
            MAX = now_mean;
    }
    cout.precision(2);
    cout << fixed << MAX;
    return 0;
}