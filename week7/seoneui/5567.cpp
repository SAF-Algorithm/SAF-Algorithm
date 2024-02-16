#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    int Ans = 0;
    cin >> N >> M;

    vector<vector<int>> relations(501);
    bool visited[501] = { false }; 


    for (int i = 0; i < M; ++i) {
        int X, Y;
        cin >> X >> Y;
        relations[X].push_back(Y);
        relations[Y].push_back(X);
    }

    for (int i = 0; i < relations[1].size(); ++i) {
        visited[relations[1][i]] = true; 
        for (int j = 0; j < relations[relations[1][i]].size(); ++j) {
            visited[relations[relations[1][i]][j]] = true; 
        }
    }

    for (int i = 2; i <= N; ++i) {
        if (visited[i])
            Ans++;
    }

    cout << Ans << endl;

    return 0;
}
