#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> dp(N + 1, vector<int>(10, 0));

    // 길이가 1인 경우는 모든 숫자가 오름차순이므로 1로 초기화
    for (int i = 0; i <= 9; i++) {
        dp[1][i] = 1;
    }

    // 길이가 2 이상인 경우
    for (int i = 2; i <= N; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = j; k <= 9; k++) {
                dp[i][k] = (dp[i][k] + dp[i - 1][j]) % 10007;
            }
        }
    }

    int result = 0;
    for (int i = 0; i <= 9; i++) {
        result = (result + dp[N][i]) % 10007;
    }

    cout << result << endl;

    return 0;
}