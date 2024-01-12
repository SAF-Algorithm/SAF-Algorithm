#include <iostream>

using namespace std;

const int MAX = 101;

int graph[MAX][MAX];
bool visited[MAX];

void dfs(int node, int n, int& count) {
    visited[node] = true;
    count++;

    for (int i = 1; i <= n; i++) {
        if (graph[node][i] && !visited[i]) {
            dfs(i, n, count);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a][b] = graph[b][a] = 1; 
    }

    int count = 0; // 바이러스에 감염된 컴퓨터의 수
    dfs(1, n, count); 

    cout << count - 1 << endl;

    return 0;
}
