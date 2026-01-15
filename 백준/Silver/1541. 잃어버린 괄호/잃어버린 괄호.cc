#include <bits/stdc++.h>
#define listp(x) for (auto y : x) cout << y << " "

using namespace std;

// 유형 : DP
// D[i] : i번쨰까지 계산했을 떄의 최솟값
// D[i] = D[i-1] + (+-v[i])
// D[0] = v[0]

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    // 입력 처리
    vector<char> signs;
    signs.push_back('+');
    vector<int> numbers;
    string inp;
    cin >> inp;

    string number = "";
    for (char c : inp) {
        if (isdigit(c)) {
            number += c;
        } else {
            signs.push_back(c);
            numbers.push_back(stoi(number));
            number = "";
        }
    }
    numbers.push_back(stoi(number));

    // 메인 로직
    int D[51];
    D[0] = numbers[0];
    for (int i = 1; i < numbers.size(); i++) {
        if (signs[i] == '-')
	        D[i] = D[i-1] - numbers[i];
        else {
            D[i] = D[i-1] + numbers[i];
            // +인 경우, 앞에 - 가 있으면 - 가능
            for (int j = 1; j <= i; j++) {
                if (signs[j] == '-') {
                    D[i] = D[i-1] - numbers[i];
                    break;
                }
            }
        }
    }

    cout << D[numbers.size() - 1] << "\n";
}