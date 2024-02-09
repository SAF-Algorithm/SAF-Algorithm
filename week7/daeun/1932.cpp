/**정수 삼각형 / 실버1 / 1932*/
#include <iostream>
#include <vector>
using namespace std;

vector< vector<int> > v(501, vector<int>(501, 0));
vector< vector<int> > mark(501, vector<int>(501, -1));


int dp(int h, int c, int n){
    int result = 0;
    if(h<0 || h>=n || c>=n) return 0;
    if(mark[h][c] != -1) return mark[h][c];

    int value1 = v[h][c] + dp(h+1, c, n);
    int value2 = v[h][c] + dp(h+1, c+1, n);

    result = max(value1, value2);
    mark[h][c] = result;
    return result;
}

int main(){
    int n;
    cin >> n;

    for(int i=0; i<n; i++)
        for(int j=0; j<=i; j++)
            cin >> v[i][j];

    cout << dp(0, 0, n);

    return 0;
}