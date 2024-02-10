/**사탕게임 / 실버2 / 3085*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector< vector<char> > v(51, vector<char>(51, 0));

int maxCandy(int n) {
    int maxCandy = 1;

    // 행을 확인
    for (int i = 0; i < n; i++) {
        int count = 1;
        for (int j = 0; j < n - 1; j++) {
            if (v[i][j] == v[i][j + 1])
                count++;
            else
                count = 1;

            maxCandy = max(count, maxCandy);
        }
    }

    // 열을 확인
    for (int i = 0; i < n; i++) {
        int count = 1;
        for (int j = 0; j < n - 1; j++) {
            if (v[j][i] == v[j + 1][i])
                count++;
            else
                count = 1;

            maxCandy = max(count, maxCandy);
        }
    }

    return maxCandy;
}

int main() {
    int n, result = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> v[i][j];

    // 행 확인
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - 1; j++) {
            if (v[i][j] != v[i][j + 1]) {
                swap(v[i][j], v[i][j + 1]);
                result = max(result, maxCandy(n)); // 최대 캔디개수
                swap(v[i][j], v[i][j + 1]);        // 되돌리기
            }
        }

    // 열 확인
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - 1; j++) {
            if (v[j][i] != v[j + 1][i]) {
                swap(v[j][i], v[j + 1][i]);
                result = max(result, maxCandy(n));
                swap(v[j][i], v[j + 1][i]);
            }
        }

    cout << result << "\n";

    return 0;
}
