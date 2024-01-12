#include <iostream>
#include <queue>

using namespace std;

int computer, connect, result = 0;
int x, y;
int arr[101][101];
queue<int> q;
bool visited[101] = {false, };

int bfs(int n) {
    q.push(n);
    visited[n] = true;

    while (!q.empty()) {
        n = q.front();
        q.pop();

        for (int i=0;i<computer;i++) {
            if (arr[n][i] == 1 && visited[i] == false) {
                q.push(i);
                visited[i] = true;
                result++;
            }
        }
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> computer >> connect;

    for (int i=0;i<connect;i++) {
        cin >> x >> y;
        arr[x][y] = 1;
        arr[y][x] = 1;
    }

    cout << bfs(1) << "\n";

    return 0;
}
