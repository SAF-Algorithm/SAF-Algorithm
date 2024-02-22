/* 숫자판 점프 / 실버2 / 2210 */
#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector< vector<int> > v (5, vector<int>(5, 0));
set<int> s;

void dfs(int i, int j, int index, int num){
    if(index == 5){
        s.insert(num);
        return;
    }

    if(i>0 && i<5 && j>=0 && j<5)
        dfs(i-1, j, index+1, num*10 + v[i-1][j]);
    if(j>0 && j<5 && i>=0 && i<5)
        dfs(i, j-1, index+1, num*10 + v[i][j-1]);
    if(i>=0 && i<4 && j>=0 && j<5)
        dfs(i+1, j, index+1, num*10 + v[i+1][j]);
    if(j>=0 && j<4 && i>=0 && i<5)
        dfs(i, j+1, index+1, num*10 + v[i][j+1]);

}

int main(){
    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
            cin >> v[i][j];
    
    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
            dfs(i, j, 0, v[i][j]);
    
    cout << s.size() << "\n";
}