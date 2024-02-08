#include <iostream>
#include <algorithm>

using namespace std;

int n, t[1002], p[1002], dp[1002];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
	cin >> n;
  
	for(int i=0; i<n; i++) {
		cin >> t[i] >> p[i];
  }

	for(int i=n-1; i>=0; i--) {
		int pos=i+t[i];
		if (pos<=n) {
			dp[i]=max(dp[pos]+p[i], dp[i+1]);
    }	else {
			dp[i]=dp[i+1];
    }
	}

  cout << dp[0] << "\n";
}
