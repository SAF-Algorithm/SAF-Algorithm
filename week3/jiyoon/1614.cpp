#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int f;
    long long max, count = 0;
    cin >> f >> max;

    if (f == 1) {
        cout << 8*max << "\n";
    } else if (f == 2) {
        count = 1;
        for (int i=1;i<=max;i++) {
            if (i % 2 == 0) {
                count += 2;
            } else {
                count += 6;
            }
        }
        cout << count << "\n";
    } else if (f == 3) {
        cout << 2 + 4*max << "\n";
    } else if (f == 4) {
        count = 3;
        for (int i=1;i<=max;i++) {
            if (i % 2 == 0) {
                count += 6;
            } else {
                count += 2;
            }
        }
        cout << count << "\n";
    } else {
        cout << 4 + 8*max << "\n";
    }

    return 0;
}
