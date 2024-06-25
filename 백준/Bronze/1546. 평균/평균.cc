#include <iostream>
using namespace std;

int main() {
    int N; // 시험을 본 과목의 개수
    int A[1000]; // 과목 데이터 저장
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    int sum = 0;
    int max = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] > max) {
            max = A[i];
        }
        sum += A[i];
    }
    
    double result = sum * 100.0 / max / N;
    cout << result << endl;
}