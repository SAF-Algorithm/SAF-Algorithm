#include <iostream>
using namespace std;

int main(){
    int n, tmp1, tmp2, tmp3, div;
    int dp[1000000] = {0, 1, 1};
    cin >> n;

    if(n <= 3){
        //1, 2, 3 입력에 대해 각각 0, 1, 1 반환
        cout << dp[n-1];
        return 0;
    }
    else{
        for(int i=3; i<=n; i++){
           if((i+1)%3==0){
                int min;
                tmp1 = dp[i-1]+1; //i의 dp값에 1 더함
                div = (i+1)/3;
                tmp3 = dp[div-1]+1; //i+1을 3으로 나눈 dp값에 1 더함
               
                if(tmp1 < tmp3)
                    min = tmp1;
                else
                    min = tmp3;
                
                //2로 나누어지는 경우에 대해 최소값 비교
                if((i+1)%2==0){
                    tmp2 = dp[(i+1)/2 - 1]+1;
                    if(min > tmp2)
                        min = tmp2;
                }
                
                dp[i] = min;

            } else if((i+1)%2==0){
                tmp1 = dp[i-1]+1;
                div = (i+1)/2;
                tmp2 = dp[div-1]+1;

                if(tmp1 < tmp2)
                    dp[i] = tmp1;
                else
                    dp[i] = tmp2;

            } else{
                dp[i] = dp[i-1]+1;
            }
        }
        cout << dp[n-1];
    }

    return 0;
}