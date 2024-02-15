#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, M, num;
	vector<int> vector;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> num;
		vector.push_back(num);
	}

	sort(vector.begin(), vector.end());

	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> num;
		cout << upper_bound(vector.begin(), vector.end(), num)
			- lower_bound(vector.begin(), vector.end(), num) << " ";
	}

	return 0;
}