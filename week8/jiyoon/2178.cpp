#include <iostream>
#include <queue>

using namespace std;

int N, M;
int arr[101][101];
int dist[101][101];
int X[] = { -1, 1, 0, 0 };
int Y[] = { 0, 0, -1, 1 };

void BFS(int y, int x) {
    queue<pair<int, int>> q;

    q.push(make_pair(y, x));

    arr[y][x] = 0;
    dist[y][x] = 1;

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;

        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int checkY = Y[i] + y;
            int checkX = X[i] + x;

            if (checkY >= 0 && checkY < N && checkX >= 0 && checkX < M)  {
                if (arr[checkY][checkX] == 1) {
                    q.push(make_pair(checkY, checkX));
                    arr[checkY][checkX] = 0;
                    dist[checkY][checkX] = dist[y][x] + 1;
                }
            }
        }
    }
}

int main() {
    cin >> N >> M;

    string s;

    for (int i = 0; i < N; i++) {
        cin >> s;

        for (int j = 0; j < M; j++) {
            arr[i][j] = s[j] - '0';
        }
    }

    BFS(0, 0);

    cout << dist[N - 1][M - 1] << '\n';

    return 0;
}
