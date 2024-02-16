#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<double> scores(N);

    for (int i = 0; i < N; ++i) {
        cin >> scores[i];
    }

    double max_score = *max_element(scores.begin(), scores.end());

    double sum = 0.0;
    for (int i = 0; i < N; ++i) {
        scores[i] = (scores[i] / max_score) * 100;
        sum += scores[i];
    }

    cout << fixed;
    cout.precision(2); // 소수점 둘째 자리까지 출력
    cout << sum / N << endl;

    return 0;
}