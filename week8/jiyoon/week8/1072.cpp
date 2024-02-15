#include <iostream>

using namespace std;

long long X, Y, Z;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> X >> Y;
    Z = Y * 100 / X;
    int cnt = -1;

    if (Z >= 99) {
        cout << cnt;

        return 0;
    }

    int left = 0, right= 1000000000;
    
    while (left <= right) {
        int mid = (left + right) / 2;
        int temp = (Y + mid) * 100 / (X + mid);
        
        if (Z < temp) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    cout << left << '\n';
}
