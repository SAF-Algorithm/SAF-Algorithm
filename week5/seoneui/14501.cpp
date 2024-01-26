#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Consultation {
    int day;
    int reward;
};

int main() {
    int n;
    cin >> n;

    vector<Consultation> consultations(n + 1);

    for (int i = 1; i <= n; ++i) {
        cin >> consultations[i].day >> consultations[i].reward;
    }

    vector<int> dp(n + 2, 0);

    for (int i = n; i >= 1; --i) {
        int nextDay = i + consultations[i].day;

        if (nextDay <= n + 1) {
            dp[i] = max(dp[i + 1], consultations[i].reward + dp[nextDay]);
        } else {
            dp[i] = dp[i + 1];
        }
    }

    cout << dp[1] << endl;

    return 0;
}
