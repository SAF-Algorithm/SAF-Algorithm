/**점프 / 실버1 / 1890*/
#include <iostream>
#include <vector>

using namespace std;
int n;
vector< vector<int> > v(101, vector<int>(101, 0));
vector< vector<long long> > dp(101, vector<long long>(101, -1));

long long search(int i, int j){
    if(i>=n || j>=n) return 0; //index 초과
    if(i==n-1 && j==n-1) return 1; //종착지
    if(v[i][j] == 0) return 0; 
    if (dp[i][j] != -1) return dp[i][j]; //중복 계산

    dp[i][j] = search(i, j + v[i][j]) + search(i + v[i][j], j);

    return dp[i][j];
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> v[i][j];

    long long result = search(0 ,0);
    cout << result;
    return 0;
}