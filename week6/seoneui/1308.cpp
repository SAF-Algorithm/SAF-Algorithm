#include <iostream>

using namespace std;

bool isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        return true; 
    }
    return false; 
}

int daysInMonth(int year, int month) {
    int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year)) {
        return 29;
    }
    return days[month];
}

int dayDifference(int year1, int month1, int day1, int year2, int month2, int day2) {
    int days = 0;

    while (!(year1 == year2 && month1 == month2 && day1 == day2)) {
        days++;
        day1++;
        if (day1 > daysInMonth(year1, month1)) {
            day1 = 1;
            month1++;
            if (month1 > 12) {
                month1 = 1;
                year1++;
            }
        }
    }

    return days;
}

int main() {
    int year1, month1, day1; 
    int year2, month2, day2; 

    cin >> year1 >> month1 >> day1;
    cin >> year2 >> month2 >> day2;

    int difference = dayDifference(year1, month1, day1, year2, month2, day2);

    if (year1 + 1000 < year2 || (year1 + 1000 == year2 && (month1 < month2 || (month1 == month2 && day1 <= day2)))) {
        cout << "gg" << endl;
    } else {
        cout << "D-" << difference << endl;
    }

    return 0;
}
