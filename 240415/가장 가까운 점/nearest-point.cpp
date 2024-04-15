#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct compare {
    bool operator()(pair<int, int> left, pair<int, int> right) {
        if (left.first + left.second > right.first + right.second)
            return true;
        if (left.first > right.first)
            return true;
        if (left.second > right.second)
            return true;
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
        cout << "D: " << top.first << ' ' << top.second << '\n';
        pq.pop();
        cout << "D2: " << pq.top().first << ' ' << pq.top().second << '\n';
        pq.push(make_pair(top.first + 2, top.second + 2));
    }

    cout << pq.top().first << ' ' << pq.top().second;

    return 0;
}