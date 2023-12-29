#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, tmp;
	cin >> N;
	vector<int> v;

	for (int i = 0; i < N; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());

	int M, num;
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> num;
		if (binary_search(v.begin(), v.end(), num)) {
			cout << "1" << "\n";
		}
		else cout << "0" << "\n";
	}

	return 0;
}
