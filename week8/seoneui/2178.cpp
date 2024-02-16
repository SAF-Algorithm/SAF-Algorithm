#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Point {
    int x;
    int y;
};

int N, M;
vector<vector<int>> maze;
vector<vector<bool>> visited;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool isValid(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M && maze[x][y] == 1 && !visited[x][y];
}

int bfs(int startX, int startY, int endX, int endY) {
    queue<Point> q;
    q.push({startX, startY});
    visited[startX][startY] = true;

    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        q.pop();

        if (x == endX && y == endY) {
            return maze[x][y];
        }

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (isValid(nx, ny)) {
                q.push({nx, ny});
                visited[nx][ny] = true;
                maze[nx][ny] = maze[x][y] + 1; 
            }
        }
    }

    return -1; 
}

int main() {
    cin >> N >> M;
    maze.resize(N, vector<int>(M));
    visited.resize(N, vector<bool>(M, false));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            char c;
            cin >> c;
            maze[i][j] = c - '0'; 
        }
    }

    int shortestDistance = bfs(0, 0, N - 1, M - 1);
    cout << shortestDistance << endl;

    return 0;
}