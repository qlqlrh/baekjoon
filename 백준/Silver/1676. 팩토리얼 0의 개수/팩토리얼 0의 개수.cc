#include <iostream>

using namespace std;

int N; // N!

/**
 * point !
 * 곱해서 끝에 0이 나오는 경우
 * 1. 10의 배수 * 숫자
 * 2. 5 * 짝수 
 * 위 두가지 경우가 몇 개나 나오는지 세면 되려나?
 * 10의 배수 개수와 5 개수?
 */

int main() {
    
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    cin >> N;

    int num = N;
    int cnt = 0;

    cnt += (num / 5);   // 5의 배수 개수 더하기
    cnt += (num / 25);  // 25의 배수 개수 더하기
    cnt += (num / 125); // 125의 배수 개수 더하기

    cout << cnt << endl;
    

}