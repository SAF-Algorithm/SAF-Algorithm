#include <iostream>
#include <queue>

using namespace std;

int main(void) {

    int n, m;
    int a, b;
    int count = 0;

    int list[501][501];
    bool isFriend[501];

    queue<int> queue;

    cin >> n >> m;

    isFriend[0] = 1;

    for (int i = 1; i <= m; i++) {

        cin >> a >> b;

        list[a][b] = 1;
        list[b][a] = 1;

        if (a == 1) {
            queue.push(b);
            isFriend[b] = 1;
            count++;
        }

        if (b == 1) {
            queue.push(a);
            isFriend[a] = 1;
            count++;
        }

    }

    while (!queue.empty()) {

        int front = queue.front();

        for (int i = 2; i <= n; i++) {
            if (list[front][i] == 1 && isFriend[i] == 0) {

                isFriend[i] = 1;
                count++;

            }
        }
        queue.pop();

    }

    cout << count;

    return 0;
}