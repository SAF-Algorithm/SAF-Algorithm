#include<iostream>
#include<algorithm>
using namespace std;
int main(void)
{
	int N;
	int dp[1000000];

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	fill_n(dp, N + 1, 1e9); 
	dp[0] = 0;
	dp[1] = 0;

	for (int i = 2; i <= N; i++) {
		if (i % 3 == 0) {
			dp[i] = min(dp[i], dp[i / 3] + 1);
		}
		if (i % 2 == 0) {
			dp[i] = min(dp[i], dp[i / 2] + 1);
		}
		dp[i] = min(dp[i], dp[i - 1] + 1);
	}

	cout << dp[N];

	return 0;
}