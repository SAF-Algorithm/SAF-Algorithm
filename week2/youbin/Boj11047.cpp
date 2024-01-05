#include<iostream>
#include<vector>
using namespace std;
int main(void)
{
	int N, K, tmp;

	cin >> N >> K;

	vector<int> v;

	for (int i = 0; i < N; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}

	int count = 0;

	for (int i = N - 1 ; i >= 0; i--) {
		if (v[i] <= K) {
			while (K - v[i] >= 0) {
				count++;
				K -= v[i];
			}
		}
	}

	cout << count;

	return 0;
}