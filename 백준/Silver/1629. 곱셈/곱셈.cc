#include <bits/stdc++.h>

using namespace std;
int A, B, C;

int recursive(int num) { // A^num = (A^(num/2))^2
    if (num == 1) return A % C;

    long long half = recursive(num / 2);
    long long result = (half * half) % C;

    if (num % 2 == 1) {  // 홀수면
        result = (result * (A % C)) % C;
    }

    return result;
}
int main() {
    cin >> A >> B >> C;

    int result = recursive(B);
    cout << result << "\n";
}