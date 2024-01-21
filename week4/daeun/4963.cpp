#include <iostream>
#include <vector>
using namespace std;
vector< int > resultVector;
int w, h;

int dfs(vector< vector<int> > &v, vector< vector<bool> > &mark, int i, int j){
    if(!mark[i][j]){
        mark[i][j] = true;

        if(j>0 && v[i][j-1]==1 && !mark[i][j-1]) 
            dfs(v, mark, i, j-1);
        if(i>0 && v[i-1][j]==1 && !mark[i-1][j]) 
            dfs(v, mark, i-1, j);
        if(i>0 && j>0 && v[i-1][j-1]==1 && !mark[i-1][j-1]) 
            dfs(v, mark, i-1, j-1);
        if(i>0 && j< mark[0].size()-1&&v[i-1][j+1]==1 && !mark[i-1][j+1]) 
            dfs(v,mark,i-1,j+1);
        if(j< mark[0].size()-1 && v[i][j+1]==1 && !mark[i][j+1])
            dfs(v, mark, i, j+1);
        if(i< mark.size()-1 && j< mark[0].size()-1 && v[i+1][j+1]==1 && !mark[i+1][j+1]) 
            dfs(v, mark, i+1, j+1);
        if(i< mark.size()-1 && v[i+1][j]==1 && !mark[i+1][j]) 
            dfs(v, mark, i+1, j);
        if(i< mark.size()-1 && j>0 && v[i+1][j-1]==1 && !mark[i+1][j-1]) 
            dfs(v, mark, i+1, j-1);
            return 1;
    }
    return 0;
}

int main(){
    while(true){
        int result = 0;
        cin >> w >> h;
        if(w == 0 && h==0) break;
        
        vector< vector<int> >v (h, vector<int>(w, 0));
        vector< vector<bool> >mark (h, vector<bool>(w, false));

        for(int i=0; i<h; i++)
            for(int j=0; j<w; j++)
               cin >> v[i][j];

        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++)
                if(v[i][j] == 1 && !mark[i][j])
                    result += dfs(v, mark, i, j);
        }
        resultVector.push_back(result);
    }

    for(int i=0; i < resultVector.size(); i++)
        cout << resultVector[i] << "\n";
    return 0;
}