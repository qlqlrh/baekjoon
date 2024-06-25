#include <iostream>
#include <string>
using namespace std;

int main() {
    int N; // 숫자의 개수
    cin >> N;
    
    string numbers; // 더해야 할 숫자
    cin >> numbers;
    
    int sum = 0;
    for (int i = 0; i < N; i++) {
        char number = numbers[i];
        sum += number - '0';
    }
    
    cout << sum << endl;
}