#include <iostream>

using namespace std;

int arr[501][501];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    int dp[1000];
    dp[0] = 1;
    dp[1] = 3;
    for (int i = 2; i < n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2] * 2)%10007;
    }

    cout << dp[n-1] << '\n';

    return 0;
}
