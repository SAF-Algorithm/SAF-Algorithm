#include<iostream>
#include<string>
#include<queue>
using namespace std;
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	queue<int> q;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string order;
		cin >> order;

		if (order == "push")
		{
			int num;
			cin >> num;
			q.push(num);
		}
		else if (order == "pop")
		{
			if (q.empty())
				cout << -1 << '\n';
			else
			{
				cout << q.front() << '\n';
				q.pop();
			}
		}
		else if (order == "size")
		{
			cout << q.size() << '\n';
		}
		else if (order == "empty")
		{
			cout << q.empty() << '\n';
		}
		else if (order == "front")
		{
			if (q.empty())
				cout << -1 << '\n';
			else
				cout << q.front() << '\n';
		}
		else if (order == "back")
		{
			if (q.empty())
				cout << -1 << '\n';
			else
				cout << q.back() << '\n';
		}
	}

	return 0;

}