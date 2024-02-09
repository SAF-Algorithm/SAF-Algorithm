/**동물원 / 실버1 / 1309*/
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, result = 1;
    cin >> n;
    vector< vector<int> > dp(n+1, vector<int>(3, 0));
    
    dp[1][0] = dp[1][1] = dp[1][2] = 1;

    if(n>1){
        for(int i=2; i<=n; i++){
            // 사자를 배치하지 않은 경우의 수
            dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % 9901;

            // 사자를 윗칸에 배치한 경우의 수
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % 9901;

            // 사자를 아랫칸에 배치한 경우의 수
            dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % 9901;
        }
    }
    
    result = (dp[n][0] + dp[n][1] + dp[n][2]) % 9901;
    cout << result;
    return 0;
}