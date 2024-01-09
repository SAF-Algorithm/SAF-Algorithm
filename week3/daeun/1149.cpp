#include <iostream>
#include <vector>

using namespace std;
vector< vector<int> > v (1001, vector<int> (3, 0));
vector<vector<int>> memo(1001, vector<int>(3, -1)); //중복 입력 기억


int search(int n, int color){
    vector<int> colorArr;

    //재귀종료
    if(n==0){
        return v[0][color];
    }

    //중복된 입력 제거, 시간초과 예방
    if (memo[n][color] != -1) {
        return memo[n][color];
    }

    //현재 색 제외한 나머지 색 명시
     for(int i=0; i<=2; i++){
       if(i!=color) colorArr.push_back(i);
    }

    //현재 사용한 색 제외 다른 색을 사용했을 떄의 최소값 + 현재 값
    int result = v[n][color] + min(search(n-1, colorArr[0]), search(n-1, colorArr[1]));
    memo[n][color] = result;
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; //집의 개수
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    }   

    cout << min(min(search(n-1, 0), search(n-1, 1)), search(n-1, 2));
    return 0;
}