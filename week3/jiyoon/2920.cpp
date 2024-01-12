#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[8];
    bool ascending = false;
    bool descending = false;

    for (int i=0;i<8;i++) {
        cin >> arr[i];
    }

    for (int i=0;i<7;i++) {
        if (arr[i] < arr[i+1]) {
            if (descending == true) {
                cout << "mixed" << "\n";
                return 0;
            } else {
                ascending = true;
            }
        } else if (arr[i] > arr[i+1]) {
            if (ascending == true) {
                cout << "mixed" << "\n";
                return 0;
            } else {
                descending = true;
            }
        }
    }

    if (ascending == true) {
        cout << "ascending" << "\n";
    } else {
        cout << "descending" << "\n";
    }

    return 0;
}
