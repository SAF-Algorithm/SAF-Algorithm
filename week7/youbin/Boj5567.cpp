#include <iostream>
#include <queue>

using namespace std;

int main(void) {

    int n, m;
    int a, b;
    int count = 0;

    int list[500][500];
    bool isFriend[500];

    queue<int> queue;

    cin >> n >> m;

    isFriend[0] = 1;

    for (int i = 0; i < m; i++) {

        cin >> a >> b;

        list[a - 1][b - 1] = 1;
        list[b - 1][a - 1] = 1;

        if (a == 1) {
            queue.push(b - 1);
            isFriend[b - 1] = 1;
            count++;
        }

        if (b == 1) {
            queue.push(a - 1);
            isFriend[a - 1] = 1;
            count++;
        }

    }

    while (!queue.empty()) {

        int front = queue.front();

        for (int i = 1; i < n; i++) {
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