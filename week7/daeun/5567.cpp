/**결혼식 / 실버2 / 5567*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int n, m, result = 0;
    cin >> n >> m;

    vector< vector<int> > v(n+1, vector<int>(n+1, 0));
    vector<int> mark(n+1, 0);

    for(int i=1; i<=m; i++){
        int a, b;
        cin >> a >> b;
        v[a][b] = 1;
        v[b][a] = 1;
    }

    queue<int> q;
    q.push(1); 

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int i=1; i<v[current].size(); i++) {
            if (!mark[i]) {
                mark[i] = mark[current] + 1;
                if (mark[i] <= 2) {
                    q.push(i);
                }
            }
        }
    }

    //친구 수 세기
    for (int i = 2; i <= n; ++i) {
        if (mark[i] > 0 && mark[i] <= 2) {
            result++;
        }
    }

    cout << result;

    return 0;
}