#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 0번 ~ 9번까지의 배열 생성
    // 입력을 char로 받아서 들어올 때마다 해당 인덱스 ++
    // 9는 6으로 치환해서 인덱스 넣기
    // 6은 나누기 2한 값으로 계산
    // 배열 중에 max 찾아서 결과로 반환

    vector<int> vec (10, 0);
    string N; // 다솜의 방 번호 (N < 1,000,000)
    cin >> N;

    for (char num : N) {
        int n = num - '0';
        if (n == 9) vec[6]++;
        else		    vec[n]++;
    }

    if (vec[6] % 2 == 0) vec[6] /= 2;
    else vec[6] = vec[6] / 2 + 1;
    auto max = max_element(vec.begin(), vec.end());

    cout << *max ;

}