#include <cstdio>
#include <vector>

using namespace std;

int main(void) {
    int M, N;
    scanf("%d %d", &M, &N);

    vector<int> vector(N + 1, 0);

    for (int i = 2; i <= N; i++) {
        vector[i] = i;
    }

    for (int i = 2; i * i <= N; i++) {
        if (vector[i] == 0) continue;
        for (int j = 2 * i; j <= N; j += i) {
            if (vector[j] == 0)  continue;
            else vector[j] = 0;
        }
    }

    for (int i = M; i <= N; i++) {
        if (vector[i] != 0) printf("%d\n", vector[i]);
    }
    return 0;
}