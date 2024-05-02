#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

priority_queue<int, vector<int>, less<int> > MAX_HEAP;
priority_queue<int, vector<int>, greater<int> > MIN_HEAP;
int benchmark;
int T;
int N;

int main() {
    // freopen_s(new FILE*, "input.txt", "r", stdin);
    cin >> T;
    int num;
    for (int tc = 1; tc <= T; tc++) {
        MAX_HEAP = priority_queue<int, vector<int>, less<int> >();
        MIN_HEAP = priority_queue<int, vector<int>, greater<int> >();
        cin >> N;
        cin >> benchmark;
        cout << benchmark << ' ';
        for (int i = 2; i <= N; i++) {
            cin >> num;
            if (num < benchmark)
                MAX_HEAP.push(num);
            else
                MIN_HEAP.push(num);
            if (MAX_HEAP.size() > MIN_HEAP.size())
            {
                MIN_HEAP.push(benchmark);
                benchmark = MAX_HEAP.top();
                MAX_HEAP.pop();
            }
            else if (MAX_HEAP.size() < MIN_HEAP.size())
            {
                MAX_HEAP.push(benchmark);
                benchmark = MIN_HEAP.top();
                MIN_HEAP.pop();
            }
            if (i % 2 == 1)
                cout << benchmark << ' ';
        }
        cout << '\n';
    }

    return 0;
}