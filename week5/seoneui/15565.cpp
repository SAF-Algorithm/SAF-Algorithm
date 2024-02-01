#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> dolls(n);

    for (int i = 0; i < n; ++i) {
        cin >> dolls[i];
    }

    int left = 0;  // 부분 연속 수열의 왼쪽 인덱스
    int right = 0; // 부분 연속 수열의 오른쪽 인덱스
    int count = 0; // 현재 부분 연속 수열에 포함된 라이언 인형의 개수
    int minLength = n + 1; // 가장 짧은 부분 연속 수열의 길이 

    while (right < n) {
        if (dolls[right] == 1) {
            count++;
        }
        
        while (count == k) {
            minLength = min(minLength, right - left + 1);

            if (dolls[left] == 1) {
                count--;
            }

            left++;
        }

        right++;
    }

    if (minLength == n + 1) {
        cout << -1 << endl;
    } else {
        cout << minLength << endl;
    }

    return 0;
}
