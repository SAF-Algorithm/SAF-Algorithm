#include <iostream>
using namespace std;

int main(){
    int n,k, count=0;
    cin >> n;
    cin >> k;

    int ary[n];
    for(int i=0; i<n; i++)
        cin >> ary[i];
    
    for(int i=n-1; i>=0; i--){
        if(k==0) break;
        else if(ary[i]>k) continue;
        else{
            count += k/ary[i];
            k %= ary[i];
        }
    }
    cout << count;
    return 0;
}