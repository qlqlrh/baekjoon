#include <iostream>
using namespace std;

int year[2], month[2], day[2]; // 0번째 : 오늘, 1번째 : D-day
int months[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

bool isLeafYear(int y) {
    if (y % 4 == 0) {
        if (y % 400 == 0)
            return true; // 윤년
        else if (y % 100 == 0)
            return false; // 평년
        else
            return true; // ** 윤년
    }
    return false; // 평년
}

void printDay() {
    int dday = 0;
    while (true) {
        if (year[1] == year[0] && month[1] == month[0] && day[1] == day[0]) // 종료 조건
            break;

        dday++;
        day[0]++;
        
        if (isLeafYear(year[0])) { // 윤년인 경우
            months[2] = 29;
        }
        else {
            months[2] = 28;
        }
        if (day[0] == months[month[0]] + 1) {
            day[0] = 1;
            month[0] += 1;
        }
        if (month[0] == 13) {
            month[0] = 1;
            year[0] += 1;
        }
    }
    cout << "D-" << dday << endl;
}

int main() {
    for (int i = 0; i < 2; i++)
        cin >> year[i] >> month[i] >> day[i];

    if (year[1] - year[0] > 1000)
        cout << "gg" << endl;
    else if (year[1] - year[0] == 1000)
        if (month[1] >= month[0] && day[1] >= day[0]) // ** 부등호 방향
            cout << "gg" << endl;
        else
            printDay();
    else
        printDay();
}

// ** 4로 나누어 떨어지면 일단 윤년이라는 거 간과함.