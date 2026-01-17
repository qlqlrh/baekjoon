#include <bits/stdc++.h>
#define pn(x) cout << x << "\n"
#define listPn(x) for(auto y : x) cout << y << " "; cout << "\n"

using namespace std;

// 시간 : 2:02 ~
// 질문 : 힙이 뭐더라...
// 유형 :

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    multiset<int> s; // 자동 정렬되는 성질 있음
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        if (num == 0) {
            if (s.empty()) cout << "0\n";
            else {
                cout << *s.begin() << "\n";
                s.erase(s.begin());
            }
        }
        else {
            s.insert(num);
        }
    }
}