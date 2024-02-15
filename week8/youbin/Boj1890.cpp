#include<iostream>
#define MAX 101
using namespace std;
long long  graph[MAX][MAX];
long long  dp[MAX][MAX] = { 0 };
int main(void)
{
	int N;

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> graph[i][j];
		}
	}

	dp[1][1] = 1;

	int jump, rightX, downY;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (dp[i][j] == 0) continue;
			if (i == N && j == N) break;

			jump = graph[i][j];
			rightX = jump + j;
			downY = jump + i;

			if (rightX <= N) dp[i][rightX] += dp[i][j];
			if (downY <= N) dp[downY][j] += dp[i][j];

		}
	}

	cout << dp[N][N];

	return 0;
}