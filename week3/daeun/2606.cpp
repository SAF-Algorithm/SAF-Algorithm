#include <iostream>
#include <vector>
using namespace std;

int result = 0;

void search(vector< vector<int> >& v, vector<bool>&mark, int i, int j){
    if(v[i][j]==1){
        mark[j] = true;

        //dfs
        for(int k = 0; k<v[0].size(); k++){
            if(v[j][k]==1 && mark[k]==false)
                search(v, mark, j, k);
        }
        result += 1;
    }
}
int main(){
    int n, m; //컴퓨터 개수, 연결된 컴퓨터 개수
    int x, y;
    cin >> n;
    cin >> m;

    vector< vector<int> > v(n, vector<int>(n, 0));
    vector< bool > mark(n, false);
    mark[0] = true;

    for(int i=0; i<m; i++){
        cin >> x;
        cin >> y;

        v[x-1][y-1] = 1;
        v[y-1][x-1] = 1;
    }

    for(int i=0; i<n; i++){
        if(mark[i]== false && v[0][i]==1){
            search(v, mark, 0, i);
        }
    }
    cout << result << "\n";
    return 0;
}