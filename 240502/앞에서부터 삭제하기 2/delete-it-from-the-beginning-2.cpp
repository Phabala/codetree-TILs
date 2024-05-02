/**
* 앞에서부터 제거해나간 뒤 (제일 작은 것 하나 뺀) 전체에서 평균의 최소값을 구하는 것은
* 뒤에서부터 쌓아간 뒤 (제일 작은 것 하나 뺀) 전체에서 평균의 최소값을 구하는 것과 같다.
*/

#include <iostream>
#include <vector>
#include <queue>

#define MAX_N 100000

using namespace std;

int n;
int arr[MAX_N];
int sum_val;
double max_avg;
priority_queue<int, vector<int>, greater<int> > pq;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    pq.push(arr[n - 1]);
    sum_val += arr[n - 1];
    for (int i = n - 2; i >= 1; i--) {
        pq.push(arr[i]);
        sum_val += arr[i];
        double avg = (double) (sum_val - (pq.top())) / (n - i - 1);
        if (max_avg < avg)
            max_avg = avg;
    }
    cout << fixed;
    cout.precision(2);
    cout << max_avg;
}