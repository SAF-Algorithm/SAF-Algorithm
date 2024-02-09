#include <iostream>
using namespace std;
int main() {
    
    int X;
    cin >> X;
    int num = 1;

    while (X > num) {
        X -= num;
        num++;
    }

    if (num % 2) {
        cout << num - (X - 1) << "/" << X;
    }
    else {
        cout << X << "/" << num - (X - 1);

    }

    return 0;

}
