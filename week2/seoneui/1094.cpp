#include <iostream>

using namespace std;

int main(){
    int X;
    int count = 0;

    cin >> X;

   while(X>0){
        if(X%2 == 1){
            count++;
        }
        X = X/2;
    }

    cout << count << endl;

    return 0;
}