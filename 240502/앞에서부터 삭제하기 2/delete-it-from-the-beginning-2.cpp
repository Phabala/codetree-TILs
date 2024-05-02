#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int sum = 0, cnt = 0;
double MAX = -21e8;

vector<int> v;
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq; // 값, 순서
int dict[100001];

int main()
{
	// freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N;
	cnt = N;
	int num;
	for (int i = 1; i <= N; i++) {
		cin >> num;
		v.push_back(num);
		pq.push(make_pair(num, i));
		sum += num;
	}
	pair<int, int> top;
	for (int k = 1; k <= N - 2; k++) {
		dict[k]++;
		cnt--;
		top = pq.top();
		pq.pop();
		while (dict[top.second] == 1)
		{
			top = pq.top();
			pq.pop();
		}
		sum -= v[k - 1];
		sum -= top.first;
		cnt--;
		MAX = max(MAX, double(sum / cnt));
		sum += top.first;
		cnt++;
	}
	cout << fixed;
	cout.precision(2);
	cout << MAX;
}

/**
* 1. N개의 정수가 주어진다. O(1)
* 2. 전체 N개의 정수들의 합을 구한다. O(1)
* 3. 앞에서 숫자 하나를 제거한다. O(logN)
* 4. 정수들의 합에서 그 숫자만큼 뺀다. O(1)
* 5. 가장 작은 수 하나를 제거한다. O(logN)
* 6. 그 수를 정수들의 합에서 뺀다. O(1)
* 7. N개 정수들의 합에서 빼진 수를 현재 남아있는 수 개수만큼 나눈다. O(1)
* 8. 아까 뺀 가장 작은 수를 다시 넣는다. O(logN)
* 9. 이 과정을 반복하며 최소값을 찾는다. O(N)
*	--> O(NlogN)
*/