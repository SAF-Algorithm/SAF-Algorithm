#include <iostream>
#include <vector>

using namespace std;

vector< vector<int> > v(101, vector<int>(101, 0));
vector<int> mark(101, 0);
int n, m, p1, p2, result = -1;

bool dfs(int start){
    if(start == p2)
        return true;

    mark[start] = 1;
    for(int i=1; i<=n; i++){
        if(v[start][i] == 1 && mark[i] == 0){
            if(dfs(i)){
                if(result != -1) result++;
                else result = 1;
                return true;
            }
        }
    }
    return false;
}

int main(){
    cin >> n >> p1 >> p2 >> m;

    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        v[x][y] = 1; v[y][x] = 1;
    }
    
    dfs(p1);

    cout << result;
    return 0;
}