#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Meeting {
    int start, end;
};

int main() {
    int n;
    cin >> n;

    vector<Meeting> meetings(n);

    for (int i = 0; i < n; ++i) {
        cin >> meetings[i].start >> meetings[i].end;
    }

    // 시작 시간을 기준으로 정렬
    //람다 사용
    sort(meetings.begin(), meetings.end(), [](Meeting a, Meeting b) {
        return a.start < b.start;
    });

    int count = 1; // 첫 번째 회의: 선택된 것으로 간주
    int endTime = meetings[0].end;

    for (int i = 1; i < n; ++i) {
        if (meetings[i].start >= endTime) {
            ++count;
            endTime = meetings[i].end;
        }
    }

    cout << count << endl;

    return 0;
}
