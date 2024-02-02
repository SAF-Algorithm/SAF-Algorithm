#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector< vector<int> > v(N+1, vector<int>(2, 0)); 
    vector<int> dp(N + 2, 0); 

    for (int i = 1; i <= N; i++) {
        cin >> v[i][0] >> v[i][1];
    }

    for (int i = N; i >= 1; i--) {
        int nextDay = i + v[i][0];

        if (nextDay <= N + 1) {
            dp[i] = max(v[i][1] + dp[nextDay], dp[i + 1]);
        } else {
            dp[i] = dp[i + 1];
        }
    }

    cout << dp[1] << endl;

    return 0;
}
