#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct compare {
    bool operator()(pair<int, int> left, pair<int, int> right) {
        if (left.first + left.second != right.first + right.second)
            return left.first + left.second > right.first + right.second;
        else if (left.first != right.first)
            return left.first > right.first;
        else if (left.second != right.second)
            return left.second > right.second;
        else
            return false;
    }
};

priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

int N, M;

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        pq.push(make_pair(x, y));
    }

    for (int i = 0; i < M; i++) {
        pair<int, int> top;
        top = pq.top();
        pq.pop();
        pq.push(make_pair(top.first + 2, top.second + 2));
    }

    cout << pq.top().first << ' ' << pq.top().second;

    return 0;
}