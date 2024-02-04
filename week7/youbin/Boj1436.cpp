#include<iostream>
#include<string>
using namespace std;
int main(void)
{
	int N, count = 0;
	cin >> N;

	int num = 666;
	string str;

	while (true) {
		str = to_string(num);
		if (str.find("666") != string::npos) {
			count++;
		}
		num++;
		if (count == N) break;
	}

	cout << str;

	return 0;
}