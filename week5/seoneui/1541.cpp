#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string expression;
    cin >> expression;

    vector<int> numbers;
    vector<char> operators;

    string num = "";
    for (char c : expression) {
        if (c == '-' || c == '+') {
            numbers.push_back(stoi(num));
            operators.push_back(c);
            num = "";
        } else {
            num += c;
        }
    }
    numbers.push_back(stoi(num)); 

    int result = numbers[0];
    bool subtract = false;

    for (int i = 0; i < operators.size(); ++i) {
        if (operators[i] == '-') {
            subtract = true;
        }
        if (subtract) {
            result -= numbers[i + 1];
        } else {
            result += numbers[i + 1];
        }
    }

    cout << result << endl;

    return 0;
}
