/* 동전1 / 골드5 /2293 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v(101,0);
vector<long long> dp(10001, 0); //합이 K일 때 경우의 수

int main(){
    int n, k;
    long long result = 0;
    cin >> n >> k;
    
    for(int i=0; i<n; i++)
        cin >> v[i];
    
    dp[0] = 1;
    
    for(int i=0; i<n; i++){
        for(int j=v[i]; j<=k; j++){
            dp[j] += dp[j - v[i]];
        }
    }

    cout << dp[k] << "\n";
    return 0;
}