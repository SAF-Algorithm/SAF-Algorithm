#include <iostream>

using namespace std;

long long g[101][101];
long long dp[101][101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i=0; i<N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> g[i][j];
        }
    }

    dp[0][0] = 1;

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            int jump = g[i][j];

            if (i != N-1 && i + jump < N) {
                dp[i + jump][j] += dp[i][j];
            }

            if (j != N-1 && j + jump < N) {
                dp[i][j + jump] += dp[i][j];
            }
        }
    }

    cout << dp[N - 1][N - 1] << '\n';

    return 0;
}
