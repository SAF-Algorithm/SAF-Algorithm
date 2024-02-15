#include <iostream>
#include <deque>

using namespace std;

deque<pair<int, int>> dq;

int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    int num;

    for (int i = 0; i < N; i++) {
        cin >> num;
        dq.push_back(make_pair(num,i+1));
    }

    while (!dq.empty()) {
        int m = dq.front().first;
        cout << dq.front().second << " ";
        dq.pop_front();
        
        if (dq.empty()) {
            break;
        }

        if (m > 0)  {
            for (int i=0; i<m-1; i++) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        } else {
            for (int i=0; i<(-1)*m; i++) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }

    cout << '\n';

    return 0;
}
