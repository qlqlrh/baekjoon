#include <iostream>
using namespace std;

// * 셀프 넘버 : 생성자가 없는 숫자
bool selfNum[10036]; // false인 게 selfNum

int main() {
    for (int i = 1; i <= 10000; i++) { // 모든 숫자에 대해서 d(n) 수행
        int num = i;
        int dn = i;
        while (num > 0) { // 자릿수만큼 반복 -> while문이 더 효율적
            dn += num % 10;
            num /= 10;
        }
        selfNum[dn] = true;
    }
    
    for (int i = 1; i < 10000; i++ ) {
        if (!selfNum[i])
            cout << i << endl;
    }
}

// ** 제일 큰 dn이 9999 + 9 + 9 + 9 + 9 = 10035