#include <iostream>

using namespace std;

int main(){
    long long n,m;
    cin >> n >> m;

    if(n == 1){
        if(m == 0){
            cout << "0" << endl;
        }
        else{
            cout << m*8 << endl;
        }

    }

    else if(n == 5){
        if(m == 0){
            cout << m*4+(n-1) << endl;
        }
        else{
            cout << m*8+4 << endl;
        }

    }

    //다친 손가락이 2, 3, 4
    else{
        if(m == 0){
            cout << m*4+(n-1) << endl;
        }
        else{
            if(m%2 != 0){
                if(n == 4){
                    cout << m*4+1 << endl;
                }
                if(n == 3){
                    cout << m*4+2 << endl;
                }
                if(n == 2){
                    cout << m*4+3 << endl;
                }
            }
            else if(m%2 == 0){
                if(n == 4){
                    cout << m*4+3 << endl;
                }
                if(n == 3){
                    cout << m*4+2 << endl;
                }
                if(n == 2){
                    cout << m*4+1 << endl;
                }
            }
        }
    }
    return 0;
}
