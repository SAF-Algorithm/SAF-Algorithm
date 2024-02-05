#include <iostream>
#include <string>

using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input;
    cin >> input;
 
    int result = 0;
    string num;
    bool flag = false;
 
    for (int i = 0; i <= input.size(); i++) {
        
        if (input[i] == '-' || input[i] == '+' || i==input.size()) {
            if (flag) {
                result -= stoi(num);
                num = "";
            }
            else {
                result += stoi(num);
                num = "";
            }
        }
        else {
            num += input[i];
        }
 
        if (input[i] == '-') {
            flag = true;
        }
    }
    
    cout << result << "\n";
}
