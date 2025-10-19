#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s; // 쇠막대기와 레이저의 배치를 나타내는 괄호 표현
    cin >> s;

    stack<char> st;
    int cnt = 0;
    int open = 0; // 쇠막대기 개수
    int size = 0;

    // () : 레이저 절단, ( ... ) 가 쇠막대기
    for (char c : s) {
        if (c == '(') open++;

        if (c == ')') {
            // case1 : 레이저, case2: 쇠막대기 끝
            if (!st.empty() && st.top() == '(') {  // 바로 앞에 top이 ( 이면 레이저 절단
                // stack에 남아있는 ( 개수만큼 cnt++
                open--; // 쇠막대기 시작이 아니라, 레이저를 의미하는 ( 제거
                // cout << "( 개수 " << open << endl;
                cnt += open;
            }
            else {
                // cout << "---쇠막대기 끝---\n";
                cnt++;
                open--;
            }
        }

        st.push(c);
    }
    cout << cnt;
}