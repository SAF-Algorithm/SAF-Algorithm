#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int weight;
    int value;
};

int knapsack(int capacity, const vector<Item>& items) {
    int n = items.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= capacity; ++w) {
            if (items[i - 1].weight > w) {
                dp[i][w] = dp[i - 1][w];
            } else {
                dp[i][w] = max(dp[i - 1][w], items[i - 1].value + dp[i - 1][w - items[i - 1].weight]);
            }
        }
    }

    return dp[n][capacity];
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<Item> items(n);

    for (int i = 0; i < n; ++i) {
        cin >> items[i].weight >> items[i].value;
    }

    int result = knapsack(k, items);

    cout << result << endl;

    return 0;
}
