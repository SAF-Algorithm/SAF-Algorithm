#include <iostream>
#include <vector>

using namespace std;

void flip(vector<vector<int>>& A, int x, int y) {
    for (int i = x; i < x + 3; ++i) {
        for (int j = y; j < y + 3; ++j) {
            A[i][j] ^= 1; // XOR 연산을 통해 뒤집기
        }
    }
}

int main() {
    int N, M;
    int count = 0; 
    bool same = true;

    cin >> N >> M;

    vector<vector<int>> A(N, vector<int>(M));
    vector<vector<int>> B(N, vector<int>(M));

    // A 행렬 입력 받기
    for (int i = 0; i < N; ++i) {
        string row;
        cin >> row;
        for (int j = 0; j < M; ++j) {
            A[i][j] = row[j] - '0';
        }
    }

    // B 행렬 입력 받기
    for (int i = 0; i < N; ++i) {
        string row;
        cin >> row;
        for (int j = 0; j < M; ++j) {
            B[i][j] = row[j] - '0';
        }
    }

    // A 행렬을 행, 열에 대해 3×3 부분행렬로 나누어 B 행렬과 비교
    for (int i = 0; i <= N - 3; ++i) {
        for (int j = 0; j <= M - 3; ++j) {
            if (A[i][j] != B[i][j]) {
                flip(A, i, j);
                count++;
            }
        }
    }

    // A 행렬과 B 행렬이 같은지 확인
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (A[i][j] != B[i][j]) {
                same = false;
                break;
            }
        }
        if (!same) break;
    }

    if (same)
        cout << count << endl;
    else
        cout << -1 << endl;

    return 0;
}
