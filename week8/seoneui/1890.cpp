#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<vector<int>> board(N, vector<int>(N));
    vector<vector<long long>> dp(N, vector<long long>(N, 0));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> board[i][j];
        }
    }

    dp[0][0] = 1;


    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int jump = board[i][j];

            if (jump == 0) 
							continue;

            if (j + jump < N) 
							dp[i][j + jump] += dp[i][j];

            if (i + jump < N) 
							dp[i + jump][j] += dp[i][j];
        }
    }

    cout << dp[N - 1][N - 1] << endl;

    return 0;
}