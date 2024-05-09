#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;

int N, M, K;

vector<int>	v1;
vector<int>	v2;
priority_queue<
	tuple<int, int, int>, // 값, v1의 i, v2의 i
	vector<tuple<int, int, int> >,
	greater<tuple<int, int, int> > > pq;

void	input()
{
	cin >> N >> M >> K;
	int num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		v1.push_back(num);
	}
	for (int i = 0; i < M; i++) {
		cin >> num;
		v2.push_back(num);
	}
}

void	solve()
{
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	for (int i = 0; i < N; i++)
		pq.push(make_tuple(v1[i] + v2[0], i, 0));
	for (int i = 0; i < K - 1; i++)
	{
		int idx1, idx2;
		tie(ignore, idx1, idx2) = pq.top();
		pq.pop();
		idx2++;
		if (idx2 < M)
			pq.push(make_tuple((v1[idx1] + v2[idx2]), idx1, idx2));
	}
	int val;
	tie(val, ignore, ignore) = pq.top();
	cout << val;
}

int main()
{
	// freopen_s(new FILE*, "input.txt", "r", stdin);
	input();
	solve();
}