#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Meeting {
    int start;
    int end;
};

bool compareMeetings(const Meeting& a, const Meeting& b) {
    if (a.end == b.end) {
        return a.start < b.start;
    }
    return a.end < b.end;
}

int main() {
    int n;
    cin >> n;

    vector<Meeting> meetings(n);

    for (int i = 0; i < n; ++i) {
        cin >> meetings[i].start >> meetings[i].end;
    }

    sort(meetings.begin(), meetings.end(), compareMeetings);

    int count = 0;  
    int endTime = 0; 

    for (int i = 0; i < n; ++i) {
        if (meetings[i].start >= endTime) {
            endTime = meetings[i].end;
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
