#include<iostream>
#include<queue>
using namespace std;

#define MAX_VALUE 1001
int N, M, V;
int mat[MAX_VALUE][MAX_VALUE];
int visited[MAX_VALUE];

void dfs(int v) {
    cout << v << ' ';
    visited[v] = 1;
    for(int i = 1; i <= N; i++) {
        if(visited[i] == 0 && mat[v][i] == 1)
            dfs(i);
    }
}

void bfs(int v) {
    queue<int> q;
    q.push(v);
    visited[v] = 1;
    
    while(!q.empty()) {
        v = q.front();
        cout << q.front() << ' ';
        q.pop();

        for(int i = 1; i <= N; i++) {
            if(visited[i] == 0 && mat[v][i] == 1) {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int x, y;
    cin >> N >> M >> V;

    for(int i = 0; i < M; i++) {
        cin >> x >> y;
        mat[x][y] = mat[y][x] = 1;
    }

    dfs(V);
    cout << '\n';

    fill(visited, visited + MAX_VALUE, 0); 
    bfs(V);

    return 0;
}
