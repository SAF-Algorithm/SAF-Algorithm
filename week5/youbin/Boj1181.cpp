#include<iostream>
#include<algorithm>
#define MAX 20000
using namespace std;
bool compare(string x, string y);
int main(void)
{
	int N;
	cin >> N;

	string str[MAX];

	for (int i = 0; i < N; i++) {
		cin >> str[i];
	}

	sort(str, str + N, compare);

	for (int i = 0; i < N; i++) {
		if (str[i] == str[i + 1]) continue;
		cout << str[i] << endl;
	}

	return 0;
}
bool compare(string x, string y) {

	if (x.length() == y.length()) return x < y;
	else return x.length() < y.length();

}