#include<iostream>
#include<queue>
using namespace std;
int abs(int n);
string bfs(int n);
struct pos
{
    int x;
    int y;
};
pos store[100];
pos festival;
pos home;
bool visited[100];
int main() {

    ios_base::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        cout << bfs(n) << endl;
    }

    return 0;
}
int abs(int n) {
    if (n < 0) return -n;
    else return n;
}
string bfs(int n) {
    fill(visited, visited + 100, false);

    cin >> home.x >> home.y;

    for (int i = 0; i < n; i++) {
        cin >> store[i].x >> store[i].y;
    }

    cin >> festival.x >> festival.y;

    queue<pair<int, int>> q;
    q.push({ home.x, home.y });

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (abs(festival.x - x) + abs(festival.y - y) <= 1000) return "happy";
        for (int i = 0; i < n; i++) {
            if (visited[i] == 1) {
                continue;
            }
            if (abs(store[i].x - x) + abs(store[i].y - y) <= 1000) {
                visited[i] = 1;
                q.push({ store[i].x, store[i].y });
            }
        }
    }
    return "sad";
}