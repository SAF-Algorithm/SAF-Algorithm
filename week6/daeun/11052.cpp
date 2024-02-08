/**카드 구매하기 / 실버1 / 11052*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> v(1001, 0); //카드 i 구매 금액 : v[i]
vector<int> mark(1001, -1);


int dp(int n){ 
    if(n == 0) return 0;

    if(mark[n]!=-1) return mark[n];

    int result = 0;
    for (int i = 1; i <= n; i++) {
        result = max(result, v[i] + dp(n - i));
    }
    mark[n] = result;
    return result;
}

int main(){
    int n;
    cin >> n;
    
    for(int i=1; i<=n; i++)
        cin >> v[i];

    cout << dp(n);

    return 0;
}