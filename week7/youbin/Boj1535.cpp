#include<iostream>
#include<algorithm>

using namespace std;

int main(void)
{
	int N;
	int L[21], J[21], dp[101] = { 0 };

	cin >> N;

	for (int i = 1; i <= N; i++) cin >> L[i];
	for (int i = 1; i <= N; i++) cin >> J[i];

	for (int i = 1; i <= N; i++) {
		for (int j = 100; j > L[i]; j--) {
			dp[j] = max(dp[j], dp[j - L[i]] + J[i]);
		}
	}

	cout << dp[100];

	return 0;
}