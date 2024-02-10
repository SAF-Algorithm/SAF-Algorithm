#include <iostream>
#include <vector>

using namespace std;

int result = 0;
vector< vector<int> > v(2, vector<int>(20, 0));
vector< vector<int> > mark(21, vector<int>(101, -1));

int search(int n, int pleasure){
    //기쁨이 0 이하일시 재귀 종료
    if(pleasure <= 0 || n < 0) return 0;

    //mark 사용
    if(mark[n][pleasure] != -1)
        return mark[n][pleasure];

    int value = search(n-1, pleasure);
    if(pleasure > v[0][n]){
        int item = v[1][n] + search(n-1, pleasure - v[0][n]);
        result = max(value, item);
    }else{
        result = value;
    }
        
    mark[n][pleasure] = result;

    return result;
}

int main(){
    int n;
    cin >> n;

    for(int i=0; i<2; i++)
        for(int j=0; j<n; j++)
            cin >> v[i][j];
    
    int result = search(n - 1, 100);
    cout << result; 

    return 0;
}