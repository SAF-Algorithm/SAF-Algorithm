#include <iostream>
#include <vector>

using namespace std;

long long dp[41] = {0};

int main() {
    int N, M;
    cin >> N >> M;

    vector<bool> isVIP(N + 1, false); 

    for (int i = 0; i < M; ++i) {
        int vipSeat;
        cin >> vipSeat;
        isVIP[vipSeat] = true; 
    }

    dp[0] = 1; 
    dp[1] = 1; 

    for (int i = 2; i <= N; ++i) {
        if (isVIP[i] || isVIP[i - 1]) {
            dp[i] = dp[i - 1];
        } else {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
    }

    cout << dp[N] << endl; 

    return 0;
}
