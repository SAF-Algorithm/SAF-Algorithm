#include <iostream>
#include <deque>

using namespace std;

int main() {
	int N;
	cin>>N;
	
	deque<int> dq;
	dq.push_back(N);

	for(int i=N-1; i>0; i--) {
		dq.push_front(i);
		for(int j=0; j<i; j++) {
			int temp = dq.back();
			dq.pop_back();
			dq.push_front(temp);
		}
	}
	
	for(int i=0; i<dq.size(); i++) {
	    cout<<dq[i]<<' ';
    }
    cout << endl;
	
    return 0;
}

