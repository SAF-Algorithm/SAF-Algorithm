#include <iostream>

using namespace std;

int arr[501][501];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<i+1; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i=n-1;i>=1;i--) {
        for(int j=0;j<i;j++) {
            arr[i-1][j] += max(arr[i][j],arr[i][j+1]);
        }
    }

    cout << arr[0][0] << '\n';

    return 0;
}
