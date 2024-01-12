#include<iostream>
using namespace std;
int main() {
    long long n, m, num = 0;
    cin >> n >> m;
    if (n == 1) num += 8 * m;
    else if (n == 5) num += 8 * m + 4;
    else {
        if (m % 2 == 1) num += 5 - n;
        else num += n - 1;
        num += 4 * m;
    }
    cout << num;
    return 0;
}