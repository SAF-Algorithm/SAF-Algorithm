#include <iostream>
using namespace std;

int main(){
    int m, n;
    cin >> m;
    cin >> n;

   /*==에라토스테네스의 체==*/
    int ary[n+1];
    for(int i=2; i<n+1; i++){
        ary[i] = i; //배열 초기화
    }
    ary[0]=0;
    ary[1]=0;

    for(int i=0; i<n+1; i++){
        //0으로 초기화되면 건너뛰기
        if(ary[i]==0) continue;

        //가능한 배수 모두 0으로 초기화
        for(int j=2*i; j<n+1; j+=i){
            ary[j] = 0;
        }
    }

    for(int i=m; i<=n; i++){
        if(ary[i]!=0)
            cout << ary[i] << "\n";
    }

    return 0;
}