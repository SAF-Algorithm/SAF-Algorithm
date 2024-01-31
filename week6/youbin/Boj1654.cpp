#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(void)
{
	int K, N;
	int tmp, result, q;
	int arr[10001];

	unsigned int left = 1, mid, right = 0;

	cin >> K >> N;

	for (int i = 0; i < K; i++) {
		cin >> tmp;
		arr[i] = tmp;
		if (right <= tmp) right = tmp;
	}

	while (left <= right) {
		mid = (left + right) / 2;

		q = 0;

		for (int i = 0; i < K; i++) {
			q += arr[i] / mid;
		}

		if (q >= N) {
			result = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	cout << result;

	return 0;
}