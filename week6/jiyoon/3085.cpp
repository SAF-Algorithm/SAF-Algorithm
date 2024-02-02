#include <iostream>
#include <algorithm>

using namespace std;

int N, maxCandy = 0;
char candy[51][51];

void countMax() {
    for (int i = 0; i < N; i++) {
        int count = 1;
        for (int j = 0; j < N; j++) {
            if (candy[i][j] == candy[i][j + 1]) {
                count++;
            } else {
                if (maxCandy < count) {
                    maxCandy = count;
                }
                count = 1;
            }
        }
    }

    for (int j = 0; j < N; j++) {
        int count = 1;
        for (int i = 0; i < N; i++) {
            if (candy[i][j] == candy[i + 1][j]) {
                count++;
            } else {
                if (maxCandy < count) {
                    maxCandy = count;
                }
                count = 1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> candy[i][j];
        }
    }
    
    for (int i = 0; i < N; i++) {
        for(int j = 0; j < N - 1; j++) {
            swap(candy[i][j], candy[i][j + 1]);
            countMax();
            swap(candy[i][j], candy[i][j + 1]);
        }
    }

    for (int j = 0; j < N; j++) {
        for(int i = 0; i < N - 1; i++) {
            swap(candy[i][j], candy[i + 1][j]);
            countMax();
            swap(candy[i][j], candy[i + 1][j]);
        }
    }

    cout << maxCandy << "\n";

    return 0;
}
