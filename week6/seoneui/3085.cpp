#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int checkCandies(const vector<string>& board, int n) {
    int maxCount = 1;

    // 가로 방향으로 연속된 사탕 개수 확인
    for (int i = 0; i < n; ++i) {
        int count = 1;
        for (int j = 1; j < n; ++j) {
            if (board[i][j] == board[i][j - 1]) {
                count++;
            } else {
                maxCount = max(maxCount, count);
                count = 1;
            }
        }
        maxCount = max(maxCount, count);
    }

    // 세로 방향으로 연속된 사탕 개수 확인
    for (int j = 0; j < n; ++j) {
        int count = 1;
        for (int i = 1; i < n; ++i) {
            if (board[i][j] == board[i - 1][j]) {
                count++;
            } else {
                maxCount = max(maxCount, count);
                count = 1;
            }
        }
        maxCount = max(maxCount, count);
    }

    return maxCount;
}

int main() {
    int n;
    cin >> n;

    vector<string> board(n);
    for (int i = 0; i < n; ++i) {
        cin >> board[i];
    }

    int result = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j + 1 < n) {
                swap(board[i][j], board[i][j + 1]);
                result = max(result, checkCandies(board, n));
                swap(board[i][j], board[i][j + 1]); 
            }

            if (i + 1 < n) {
                swap(board[i][j], board[i + 1][j]);
                result = max(result, checkCandies(board, n));
                swap(board[i][j], board[i + 1][j]); 
            }
        }
    }

    cout << result << endl;

    return 0;
}
