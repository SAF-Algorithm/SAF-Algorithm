#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 50;

int w, h;
vector<vector<int> > map(MAX, vector<int>(MAX, 0));
vector<vector<bool> > visited(MAX, vector<bool>(MAX, false)); 

int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};

void bfs(int x, int y) {
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));
    visited[x][y] = true;

    while (!q.empty()) {
        int currentX = q.front().first;
        int currentY = q.front().second;
        q.pop();

        for (int i = 0; i < 8; ++i) {
            int nextX = currentX + dx[i];
            int nextY = currentY + dy[i];

            if (nextX >= 0 && nextX < h && nextY >= 0 && nextY < w &&
                map[nextX][nextY] == 1 && !visited[nextX][nextY]) {
                q.push(make_pair(nextX, nextY));
                visited[nextX][nextY] = true;
            }
        }
    }
}

int countIslands() {
    int islandCount = 0;

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (map[i][j] == 1 && !visited[i][j]) {
                bfs(i, j);
                islandCount++;
            }
        }
    }

    return islandCount;
}

int main() {
    while (true) {
        cin >> w >> h;

        if (w == 0 && h == 0) 
            break; 

        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                cin >> map[i][j];
                visited[i][j] = false; 
            }
        }

        int result = countIslands();
        cout << result << endl;
    }

    return 0;
}
