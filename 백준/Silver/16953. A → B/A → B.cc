#include <bits/stdc++.h>
#define pn(x) cout << x << "\n"
#define listPn(x) for (auto y : x) cout << y << " "; cout << "\n"

using namespace std;

// 유형 : 백트래킹..?

int A, B;
int current;
int cnt = INT_MAX;
vector<int> result;

void backtrack(long long num) {
    if (num == B) {
        int size = result.size();
        cnt = min(cnt, size);
        // listPn(result);
        return;
    }

    for (int i = 0; i < 2; i++) {
        if (num > B) continue;
        result.push_back(num);
        if (i == 0) { // 곱하기 2
            backtrack(num * 2);
        }
        else { // 곱하기 10 + 1
            backtrack(num * 10 + 1);
        }
        result.pop_back();
    }


}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> A >> B;

    backtrack(A);

    if (cnt == INT_MAX) pn("-1");
    else pn(cnt + 1);
}