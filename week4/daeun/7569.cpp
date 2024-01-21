#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int m, n, h; //가로, 세로, 높이
int result = 0;


struct tomato {
    int x;
    int y;
    int z;
};


void search(vector< vector< vector<int> > > &v, vector< vector< vector<int> > > &mark, 
queue<tomato>& tomatoQueue){

    while (!tomatoQueue.empty()) {
        tomato current = tomatoQueue.front();
        tomatoQueue.pop();

        int i = current.x;
        int j = current.y;
        int z = current.z;

    if (z < v.size() - 1 && v[z + 1][i][j] == 0 && mark[z+1][i][j] == 0) {
        v[z+1][i][j] = v[z][i][j] + 1;
        mark[z+1][i][j] = 1;
        tomatoQueue.push((tomato){i, j, z+1});
    }

    if (i < v[0].size() - 1 && v[z][i + 1][j] == 0 && mark[z][i + 1][j] == 0) {
        v[z][i+1][j] = v[z][i][j] + 1;
        mark[z][i+1][j] = 1;
        tomatoQueue.push((tomato){i+1, j, z});
    }
    if (j < v[0][0].size() - 1 && v[z][i][j + 1] == 0 && mark[z][i][j + 1] == 0) {
        v[z][i][j + 1] = v[z][i][j] + 1;
        mark[z][i][j+1] = 1;
        tomatoQueue.push((tomato){i, j+1, z});
    }
    if (i > 0 && v[z][i - 1][j] == 0 && mark[z][i - 1][j] == 0) {
        v[z][i - 1][j] = v[z][i][j] + 1;
        mark[z][i-1][j] = 1;
        tomatoQueue.push((tomato){i-1, j, z});
    }
    if (j > 0 && v[z][i][j - 1] == 0 && mark[z][i][j - 1] == 0) {
        v[z][i][j - 1] = v[z][i][j] + 1;
        mark[z][i][j-1] = 1;
        tomatoQueue.push((tomato){i, j-1, z});
    }

    if (z > 0 && v[z - 1][i][j] == 0 && mark[z - 1][i][j] == 0) {
        v[z - 1][i][j] = v[z][i][j] + 1;
        mark[z-1][i][j] = 1;
        tomatoQueue.push((tomato){i, j, z-1});
    }
    }
}

int main(){

     cin >> m >> n >> h;

    vector< vector< vector<int> > > v(h, vector< vector<int> >(n, vector<int>(m, 0)));
    vector< vector< vector<int> > > mark(h, vector< vector<int> >(n, vector<int>(m, 0)));

    queue<tomato> tomatoQueue;

    for(int k=0; k<h; k++)
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> v[k][i][j];
        }
    }

    for(int k=0; k<h; k++)
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++){
                if(mark[k][i][j]==0 && v[k][i][j] == 1){
                    mark[k][i][j] = 1;
                    tomatoQueue.push((tomato){i, j, k});
                }
        }

    search(v, mark, tomatoQueue);

    int maxResult = 0;
    for(int k=0; k<h; k++)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (v[k][i][j] == 0) {
                    cout << "-1";
                    return 0;
                }
                maxResult = max(maxResult, v[k][i][j] - 1);
            }
        }

    cout << maxResult;

    return 0;
}