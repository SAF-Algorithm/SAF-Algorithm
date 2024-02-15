#include <iostream>

using namespace std;

int n, m;
int arr[501][501];
bool visited[501];
bool friends[501];

int BFS() {
    int count = 0;

    for (int i=2; i<=n; i++) {
        if (arr[1][i] == 1) {
            visited[i] = true;
            friends[i] = true;
        }
    }

    for (int i=2; i<=n; i++) {
        if (friends[i]) {
            for (int j=1; j<=n; j++) {
                if (arr[i][j]) {
                    visited[j] = true;
                }
            }
        }
    }

    for (int i=2; i<=n; i++) {
        if (visited[i]) {
            count++;
        }
    }

    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    while (m--) {
        int a, b;
        cin >> a >> b;
        arr[a][b] = 1;
        arr[b][a] = 1;
    }

    cout << BFS() << "\n";

    return 0;
}
