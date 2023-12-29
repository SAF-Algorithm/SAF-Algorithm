#include <iostream>

using namespace std;

int main() {
    int L, P, V, left;
    int count = 0;
    int *result = new int[1000];

    while (true) {
        cin >> L >> P >> V;

        if (L == 0 && P == 0 && V == 0) {
            break;
        }

        int cel = V / P;
        left = V % P;
        result[count] = L * cel + min(L, left);
        count ++;
    }

    for(int i = 0; i<count; i++){
        cout << "Case " << i+1 << ": " << result[i] << endl;
    }

    delete[] result;

    return 0;
}
