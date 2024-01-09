#include <vector>
#include <iostream>
using namespace std;

int search(vector< vector<int> >& v, vector< vector<bool> >&mark, int i, int j){
 if(v[i][j]==1){
    mark[i][j] = true;
    if (i < v.size() - 1 && v[i + 1][j] == 1 && mark[i + 1][j] == false) {
        search(v, mark, i + 1, j);
    }
    if (j < v[0].size() - 1 && v[i][j + 1] == 1 && mark[i][j + 1] == false) {
        search(v, mark, i, j + 1);
    }
    if (i > 0 && v[i - 1][j] == 1 && mark[i - 1][j] == false) {
        search(v, mark, i - 1, j);
    }
    if (j > 0 && v[i][j - 1] == 1 && mark[i][j - 1] == false) {
        search(v, mark, i, j - 1);
    }
    return 1;
 }
 else
    return 0;
}

int main(){
    int t, n, m, k;
    cin >> t;

    while(--t >= 0){
        cin >> m; //가로길이
        cin >> n; //세로길이
        cin >> k;

        int count = 0, x, y;
        vector< vector<int> > v(n, vector<int>(m, 0));
        vector< vector<bool> > mark(n, vector<bool>(m, false));
        for(int i=0; i<k; i++){
           cin >> x;
           cin >> y;

           v[y][x] = 1;
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mark[i][j]== false && v[i][j]==1){
                    count += search(v, mark, i, j);
                }
            }
        }
        cout << count << "\n";
    }
    return 0;
}