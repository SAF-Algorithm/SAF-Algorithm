#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> node;
vector<bool> visited;
int M, N;
int result = 0;

void dfs(int x){
    visited[x] = true;
    result += 1;

    for(int i = 1; i<= M; i++){
        if(node[x][i] == 1 && !visited[i]){
            dfs(i);
        }
    }
}

int main(){
    cin >> M >> N;

    node = vector<vector<int>>(M+1, vector<int>(M+1, 0));
    visited = vector<bool>(M+1, false);

    for(int i=0; i<N; i++){
       int m, n;
       cin >> m >> n;
       node[m][n] = node[n][m] = 1;
    }

    dfs(1);
    cout << result-1;

    return 0;
}