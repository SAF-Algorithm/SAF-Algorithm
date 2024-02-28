#include<iostream>
#include<set>
using namespace std;
int pos[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
int graph[5][5];
set<int>s;
void dfs(int x, int y, int num, int count)
{

	if (count == 6) {
		s.insert(num);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int newX = x + pos[i][0];
		int newY = y + pos[i][1];

		if (newX < 0 || newY < 0 || newX >= 5 || newY >= 5) continue;
		dfs(newX, newY, num * 10 + graph[newX][newY], count + 1);
	}

}
int main(void)
{
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> graph[i][j];
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			dfs(i, j, graph[i][j], 1);
		}
	}

	cout << s.size();

	return 0;
}
