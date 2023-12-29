#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int n, remain = -1, ip;
    cin >> n;
    int num[10001] = {0};
    char ary[6];

    for (int i = 0; i < n; i++) {
        cin >> ary;

        if (strcmp(ary, "push") == 0) {
            cin >> ip;
            remain++;
            num[remain] = ip;
        } else if (strcmp(ary, "pop") == 0) {
            if (remain == -1)
                cout << "-1\n";
            else {
                cout << num[remain] << "\n";
                num[remain] = 0;
                remain--;
            }
        } else if (strcmp(ary, "size") == 0) {
            cout << remain + 1 << "\n";
        } else if (strcmp(ary, "empty") == 0) {
            if (remain == -1)
                cout << "1\n";
            else
                cout << "0\n";
        } else if (strcmp(ary, "top") == 0) {
            if (remain == -1)
                cout << "-1\n";
            else
                cout << num[remain] << "\n";
        }
    }
    return 0;
}
