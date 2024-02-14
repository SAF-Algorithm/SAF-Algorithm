#include<iostream>
#include<queue>
#define MAX 101
using namespace std;
int graph[MAX][MAX];
bool visited[MAX][MAX];
int dist[MAX][MAX];
int pos[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
int bfs(int N, int M)
{
	queue<pair<int, int>> queue;

	queue.push(make_pair(1, 1));

	visited[1][1] = true;
	dist[1][1] = 1;

	while (!queue.empty()) {

		pair<int, int> curr = queue.front();
		queue.pop();

		if (curr.first == N && curr.second == M) return dist[N][M];

		for (int i = 0; i < 4; i++) {

			int newX = curr.first + pos[i][0];
			int newY = curr.second + pos[i][1];

			if (newX >= 1 && newX <= N && newY >= 1 && newY <= M && !visited[newX][newY] && graph[newX][newY] == 1) {
				queue.push(make_pair(newX, newY));
				visited[newX][newY] = true;
				dist[newX][newY] = dist[curr.first][curr.second] + 1;
			}
		}
	}

	return -1;
}
int main(void)
{
	int N, M;
	string str;

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		cin >> str;

		for (int j = 1; j <= M; j++) {
			graph[i][j] = str[j - 1] - '0';
		}
	}

	cout << bfs(N, M);

	return 0;
}
