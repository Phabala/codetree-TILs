#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

int								N, M;
char							group_a[500][51];
char							group_b[500][51];
vector<unordered_set<string>>	v_us_a;
vector<unordered_set<string>>	v_us_b;

void	char_input(char group_x[][51])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cin >> group_x[i][j];
	}
}

void	v_us_push_back(int i, int j, int k)
{
	unordered_set<string> us_a;
	unordered_set<string> us_b;

	for (int n = 0; n < N; n++)
	{
		string a;
		string b;

		a += group_a[n][i];
		a += group_a[n][j];
		a += group_a[n][k];

		b += group_b[n][i];
		b += group_b[n][j];
		b += group_b[n][k];

		us_a.insert(a);
		us_b.insert(b);
	}
	v_us_a.push_back(us_a);
	v_us_b.push_back(us_b);
}

int	get_ans()
{
	int	cnt;
	int	is_tellable;

	cnt = 0;
	is_tellable = 1;
	if (v_us_a.size() != v_us_b.size())
		return -21e8;
	for (int i = 0; i < v_us_a.size(); i++)
	{
		for (auto it_a = v_us_a[i].begin(); it_a != v_us_a[i].end(); it_a++)
		{
			for (auto it_b = v_us_b[i].begin(); it_b != v_us_b[i].end(); it_b++)
			{
				if (*it_a == *it_b)
				{
					is_tellable = 0;
					break;
				}
			}
			if (!is_tellable)
			{
				is_tellable = 1;
				cnt--;
				break;
			}
		}
		cnt++;
	}
	return (cnt);
}

int	main(void)
{
	int	ans;

	// input & reset
	// freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N >> M;
	char_input(group_a);
	char_input(group_b);

	// solve
	for (int i = 0; i < M - 2; i++)
	{
		for (int j = i + 1; j < M - 1; j++)
		{
			for (int k = j + 1; k < M; k++)
				v_us_push_back(i, j, k);
		}
	}
	ans = get_ans();

	// output
	cout << ans;
	return (0);
}

/**
* 64가지 조합이 있으며 각각의 위치에 (i, j, k 순서에 맞게) 조합을 unordered_set 
* 해둔 다음, B 그룹에서도 unordered_set 해두고, 각각의 index 마다 같은게 있는지 
* 찾는다.
* 50 * 50 * 50 + 50 * 50 * 50 + 500 * 500 * 50 = 12,750,000
* 각각 조합이 64개니까 하나의 조합을 비트로 만들어 64비트로 만든 다음 & 연산해서
* 계산하면 10,000,000 번 정도 시간을 줄일 수 있다.
*/