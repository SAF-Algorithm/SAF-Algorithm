#include<iostream>
#include<vector>
using namespace std;
int main(void)
{
	int a, b, c;
	int x, y, z;
	vector<string> res;

	while (true) {
		cin >> a >> b >> c;

		if (a == 0 && b == 0 && c == 0) break;

		if (a < c && b < c) {
			x = a; y = b; z = c;
		}
		else if (a < b && c < b) {
			x = a; y = c; z = b;
		}
		else {
			x = b; y = c; z = a;
		}


		if (x * x + y * y == z * z) res.push_back("right");
		else res.push_back("wrong");

	}

	for (auto& i : res) cout << i << endl;

	return 0;
}