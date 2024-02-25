#include<iostream>
#include<vector>
#define MAX 1000000000
using namespace std;

int N;
vector<int> num, op;
int maximum = -MAX, minimum = MAX;

void calculate(int index, int result)
{
	if (index == N) {
		minimum = min(minimum, result);
		maximum = max(maximum, result);

		return;
	}

	if (op[0] > 0) {
		op[0]--;
		calculate(index + 1, result + num[index]);
		op[0]++;
	}
	if (op[1] > 0) {
		op[1]--;
		calculate(index + 1, result - num[index]);
		op[1]++;
	}
	if (op[2] > 0) {
		op[2]--;
		calculate(index + 1, result * num[index]);
		op[2]++;
	}
	if (op[3] > 0) {
		op[3]--;
		calculate(index + 1, result / num[index]);
		op[3]++;
	}

}

int main(void)
{
	cin >> N;
	int tmp;

	for (int i = 0; i < N; i++) {
		cin >> tmp;
		num.push_back(tmp);
	}

	for (int i = 0; i < 4; i++) {
		cin >> tmp;
		op.push_back(tmp);
	}

	calculate(1, num[0]);

	cout << maximum << endl;
	cout << minimum << endl;

	return 0;
}
