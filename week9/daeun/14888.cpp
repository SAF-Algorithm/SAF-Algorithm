/* 연산자 끼워넣기 / 실버1 / 14888 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n; //수의 개수
long long maxResult = -1e9;
long long minResult = 1e9;

vector<int> v (11, 0);
vector<int> oper(4,0);


void dfs(int i, long long result, int plus, int minus, int multi, int div){
    if(i == n){
        maxResult = max(maxResult, result);
        minResult = min(minResult, result);
        return;
    }

    if(plus > 0)
        dfs(i+1, result + v[i], plus-1, minus, multi, div);
     if(minus > 0)
        dfs(i+1, result - v[i], plus, minus-1, multi, div);
     if(multi > 0)
        dfs(i+1, result * v[i], plus, minus, multi-1, div);
     if(div > 0){
        int divTemp;
        if(result > 0){
            divTemp = -(-result)/v[i];
            dfs(i+1, divTemp, plus, minus, multi, div-1);
        } else
            dfs(i+1, result / v[i], plus, minus, multi, div-1);
     }

}

int main(){
    cin >> n;

    for(int i=0; i<n; i++)
        cin >> v[i];
    
    //연산자 입력
    for(int i=0; i<4; i++)
        cin >> oper[i]; 

    dfs(1, v[0], oper[0], oper[1], oper[2], oper[3]);
    
    cout << maxResult << "\n" << minResult << "\n";

}