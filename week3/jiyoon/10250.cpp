#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, H, W, N;
    cin >> T;

    for (int i=0;i<T;i++) {
        cin >> H >> W >> N;
        if (N%H != 0) {
            if (N/H+1 > 9) {
                cout << N%H << N/H+1;
            } else {
                cout << N%H << "0" << N/H+1;
            }
        } else {
            if (N/H > 9) {
                cout << H << N/H;
            } else {
                cout << H << "0" << N/H;
            }
        }

        cout << "\n";
    }

    return 0;
}
