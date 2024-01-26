#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Lecture {
    int start;
    int end;
};

struct CompareEnd {
    bool operator()(const Lecture& a, const Lecture& b) {
        return a.end > b.end;  
    }
};

bool compareLectures(const Lecture& a, const Lecture& b) {
    return a.start < b.start;
}

int main() {
    int n;
    cin >> n;

    vector<Lecture> lectures(n);

    for (int i = 0; i < n; ++i) {
        cin >> lectures[i].start >> lectures[i].end;
    }

    // 시작 시간을 기준으로 정렬
    sort(lectures.begin(), lectures.end(), compareLectures);

    // 종료 시간을 기준으로 최소 힙 정렬
    priority_queue<Lecture, vector<Lecture>, CompareEnd> minHeap;

    minHeap.push(lectures[0]);

    for (int i = 1; i < n; ++i) {
        if (minHeap.top().end > lectures[i].start) {
            minHeap.push(lectures[i]);
        } else {
            Lecture temp = minHeap.top();
            minHeap.pop();
            temp.end = lectures[i].end;
            minHeap.push(temp);
        }
    }

    cout << minHeap.size() << endl;

    return 0;
}
