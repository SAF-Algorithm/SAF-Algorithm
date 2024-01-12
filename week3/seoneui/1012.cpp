#include <iostream>

using namespace std;

const int MAX = 50;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(int x, int y, int field[MAX][MAX], bool visited[MAX][MAX], int M, int N) {
    visited[x][y] = true;

    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];

        if (nx >= 0 && nx < M && ny >= 0 && ny < N && field[nx][ny] && !visited[nx][ny]) {
            dfs(nx, ny, field, visited, M, N);
        }
    }
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int M, N, K;
        cin >> M >> N >> K;

        int field[MAX][MAX] = {0};
        bool visited[MAX][MAX] = {false};

        for (int i = 0; i < K; i++) {
            int x, y;
            cin >> x >> y;
            field[x][y] = 1;
        }

        int count = 0; 

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (field[i][j] && !visited[i][j]) {
                    dfs(i, j, field, visited, M, N);
                    count++;
                }
            }
        }

        cout << count << endl;
    }

    return 0;
}
