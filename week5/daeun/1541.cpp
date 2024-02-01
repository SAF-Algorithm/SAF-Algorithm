#include <iostream>
#include <string>

using namespace std;

int main() {
    string exp;
    cin >> exp;

    int result = 0;
    int num = 0;
    bool is_minus = false;

    for (char c : exp) {
        if (c == '+' || c == '-') {
            result += (is_minus ? -num : num);
            if (c == '-') {
                is_minus = true;
            }
            num = 0;
        } else {
            num = num * 10 + (c - '0');
        }
    }

    // 마지막 숫자
    result += (is_minus ? -num : num);

    cout << result << endl;

    return 0;
}
