#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int seats[100001];
vector<pair<int, int>> v_p; // 자리바꿈
vector<unordered_set<int>> v_us; // 각 사람이 앉은 자리들

void    debug_print(int N)
{
	int cnt;
	int	k;
	int	n;

	k = 0;
	for (n = 1; n <= N; n++) {
		cnt = 0;
		for (auto it = v_us[n].begin(); it != v_us[n].end(); it++)
			cnt++;
		cout << "DEBUG: " << n << ": " << cnt << '\n';
	}
}

void    output(int N)
{
	int cnt;
	int	k;
	int	n;

	k = 0;
	for (n = 1; n <= N; n++) {
		cnt = 0;
		for (auto it = v_us[n].begin(); it != v_us[n].end(); it++)
			cnt++;
		cout << cnt << '\n';
	}
}

void    one_k(int N, int K)
{
	int k;
	int tmp;

	k = 0;
	while (k < K)
	{
		v_us[seats[v_p[k].first]].insert(v_p[k].second);
		v_us[seats[v_p[k].second]].insert(v_p[k].first);
		tmp = seats[v_p[k].first];
		seats[v_p[k].first] = seats[v_p[k].second];
		seats[v_p[k].second] = tmp;
		k++;
	}
}

int main() {
	// input & reset
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	int N, K;
	cin >> N >> K;

	unordered_set<int> us;
	for (int n = 0; n <= N; n++) {
		v_us.push_back(us);
		v_us[n].insert(n);
		seats[n] = n;
	}
	for (int k = 0; k < K; k++) {
		pair<int, int> tmp;
		cin >> tmp.first >> tmp.second;
		v_p.push_back(tmp);
	}

	// solve
	one_k(N, K);
	one_k(N, K);
	one_k(N, K);

	// output
    output(N);
	return 0;
}