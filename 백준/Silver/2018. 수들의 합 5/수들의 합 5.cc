#include <iostream>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; // 자연수 (1 <= N <= 10,000,000)
    cin >> N;

    // 이렇게 하면 메모리 초과남
    // vector<int> numbers (N, 0);
    // for (int i = 0; i < N; i++) {
    //     numbers[i] = i + 1; // 값 세팅
    // }

    // 투 포인터 세팅
    // vector<int>::iterator begin = numbers.begin();
    // vector<int>::iterator end   = numbers.begin();
    int begin = 1;
    int end = 1;
    int sum = 1;
    int cnt = 1;
    while (end != N) { // end == N이 되면 종료 (따라서 애초에 N=1이면 while문 안 돌아감)
        // int sum = accumulate(begin, end, 0); // numeric header에 있음 (algorithm 아님 주의)
        if (sum < N) {
            end++;
            sum += end;
        }
        else if (sum > N) {
            sum -= begin;
            begin++;

        }
        else { // sum == N
            cnt++;
            end++;
            sum += end;
        }
    }

    cout << cnt << "\n";
}