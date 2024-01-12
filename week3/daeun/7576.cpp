#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int m,n; //가로, 세로
int result = 0;

struct tomato {
    int x;
    int y;
};

void search(vector< vector<int> >& v, vector< vector<int> >&mark, 
queue<tomato>& tomatoQueue){

    while (!tomatoQueue.empty()) {
        tomato current = tomatoQueue.front();
        tomatoQueue.pop();

        int i = current.x;
        int j = current.y;

    if (i < v.size() - 1 && v[i + 1][j] == 0 && mark[i + 1][j] == 0) {
        v[i+1][j] = v[i][j] + 1;
        mark[i+1][j] = 1;
        tomatoQueue.push((tomato){i+1, j});
    }
    if (j < v[0].size() - 1 && v[i][j + 1] == 0 && mark[i][j + 1] == 0) {
        v[i][j + 1] = v[i][j] + 1;
        mark[i][j+1] = 1;
        tomatoQueue.push((tomato){i, j+1});
    }
    if (i > 0 && v[i - 1][j] == 0 && mark[i - 1][j] == 0) {
        v[i - 1][j] = v[i][j] + 1;
        mark[i-1][j] = 1;
        tomatoQueue.push((tomato){i-1, j});
    }
    if (j > 0 && v[i][j - 1] == 0 && mark[i][j - 1] == 0) {
        v[i][j - 1] = v[i][j] + 1;
        mark[i][j-1] = 1;
        tomatoQueue.push((tomato){i, j-1});
    }
    
    }
}

int main(){
    cin >> m >> n;

    vector< vector<int> > v(n, vector<int>(m, 0));
    vector< vector<int> > mark(n, vector<int>(m, 0));
    queue<tomato> tomatoQueue;


    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> v[i][j];
        }
    }

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++){
            if(mark[i][j]==0 && v[i][j] == 1){
                mark[i][j] = 1;
                tomatoQueue.push((tomato){i, j});
            }
        }

    search(v, mark, tomatoQueue);

    int maxResult = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == 0) {
                cout << "-1";
                return 0;
            }
            maxResult = max(maxResult, v[i][j] - 1);
        }
    }

    cout << maxResult;

    return 0;
}