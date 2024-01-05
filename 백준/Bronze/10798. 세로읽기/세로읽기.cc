#include <iostream>
using namespace std;

char arr[5][15]; // 전역 변수로 선언해야 빈칸이 NULL이나 \0으로 초기화 됨!!

int main() {
    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
    }
    
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 5; j++) {
            if (arr[j][i] != '\0') {
                cout << arr[j][i];   
            }
        }
    }
}