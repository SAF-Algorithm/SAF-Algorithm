#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> A(N);

    for (int i = 0; i < N; ++i) {
        cin >> A[i].first;
        A[i].second = i; 
    }

  
    sort(A.begin(), A.end());

    vector<int> B(N); 
    for (int i = 0; i < N; ++i) {
        B[A[i].second] = i; 
    }

    for (int i = 0; i < N; ++i) {
        cout << B[i] << " ";
    }
    cout << endl;

    return 0;
}