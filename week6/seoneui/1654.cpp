#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long getMaxPossibleLength(const vector<int>& lan, int k) {
    long long left = 1; 
    long long right = *max_element(lan.begin(), lan.end()); 

    while (left <= right) {
        long long mid = (left + right) / 2; 

        int count = 0;
        for (int l : lan) {
            count += (l / mid);
        }

        if (count >= k) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return right;
}

int main() {
    int k, n;
    cin >> k >> n;

    vector<int> lan(k);
    for (int i = 0; i < k; ++i) {
        cin >> lan[i];
    }

    long long maxLength = getMaxPossibleLength(lan, n);
    cout << maxLength << endl;

    return 0;
}
