#include <iostream>

using namespace std;

int main(){
    int N,K;
    int count = 0;

    cin >> N >> K;  
    
    int arr[N];
    for(int i =0; i<N; i++){
        cin >> arr[i];
    }

    while(K){
        for(int i = N-1; i>=0; i--){
            while(K-arr[i] >= 0){
                K = K - arr[i];
                count++; 
            }
        }
    }

    cout << count;

    return 0;
}