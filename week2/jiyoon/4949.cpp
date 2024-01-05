#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string str;

    bool flag;

    while (true) {
        stack<char> s;
        cin >> str;

        if (str == ".") {
            break;
        }

        flag = true;

        for (int i=0;i<str.size();i++) {
            if(str[i] == '[' || str[i] == '(') {
                s.push(str[i]);
            }

            else if (str[i] == ']') {
                if (s.empty()) {
                    flag = false;
                    break;
                }

                else if (s.top() == '[') {
                    s.top();
                }
            }

            else if (str[i] == ')') {
                if (s.empty()) {
                    flag = false;
                    break;
                }

                else if (s.top() == '(') {
                    s.top();
                }
            }
        }

        if (s.empty() && flag) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
    
    return 0;
}
