#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 101;

int n;
vector<int> graph[MAX]; // 가족 관계를 나타내는 그래프
int start, last; // 촌수를 계산할 두 가족 구성원

int bfs() {
    queue<int> q;
    vector<int> visited(MAX, 0);

    q.push(start);
    visited[start] = 1;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int i = 0; i < graph[current].size(); ++i) {
            int next = graph[current][i];

            if (!visited[next]) {
                q.push(next);
                visited[next] = visited[current] + 1;

                if (next == last) {
                    return visited[next] - 1; 
                }
            }
        }
    }

    return -1; 
}

int main() {
    cin >> n;
    cin >> start >> last;

    int m; 
    cin >> m;

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    int result = bfs();

    cout << result << endl;

    return 0;
}
