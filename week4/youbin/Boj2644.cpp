#include<iostream>
#include<queue>
using namespace std;
#define MAX 101
int arr[MAX][MAX];
int visited[MAX] = { 0 };
void bfs(int a, int n) {
	queue<int> queue;

	queue.push(a);

	while (!queue.empty()) {
		a = queue.front();
		queue.pop();

		for (int i = 1; i <= n; i++) {
			if (arr[a][i] != 0 && !visited[i]) {
				queue.push(i);
				visited[i] = visited[a] + 1;
			}
		}
	}


}
int main(void)
{
	int n, m;
	int targetA, targetB;
	int x, y;

	cin >> n >> targetA >> targetB >> m;

	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		arr[x][y] = 1;
		arr[y][x] = 1;
	}

	bfs(targetA, n);

	if (visited[targetB] == 0) cout << -1;
	else cout << visited[targetB];

	return 0;
}