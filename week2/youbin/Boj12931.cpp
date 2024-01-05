#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int N, tmp;
    int count = 0;
    cin >> N;

    vector<int> B;

    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        B.push_back(tmp);
    }

    while (true)
    {
        int zero = 0, even = 0;
        for (auto& i : B)
        {
            if (i % 2 != 0)
            {
                count++;
                i--;
            }
            else  even++;
            if (i == 0)  zero++;
        }

        if (zero == N) break;

        if (even == N)
        {
            count++;
            for (auto& i : B) i = i / 2;
        }
    }

    cout << count;

    return 0;
}