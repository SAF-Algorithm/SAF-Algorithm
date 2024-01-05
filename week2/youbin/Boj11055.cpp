#include<iostream>
#include<algorithm>
using namespace std;
int main(void)
{
	int N;
	cin >> N;

	int A[1001];
	int dp[1001];

	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		dp[i] = A[i] = tmp;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (A[j] < A[i]) {
				dp[i] = max(dp[i], dp[j] + A[i]);
			}
		}
	}

	sort(dp, dp + N);
	cout << dp[N - 1];

	return 0;
}