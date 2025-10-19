#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        string s;
        cin >> s;

        stack<char> st;
        bool flag = true;
        for (char c : s) {
            if (c == '(') st.push(c);
            else if (!st.empty() && st.top() == '(') {
                st.pop();
            }
            else {
                flag = false;
                break;
            }
        }

        if (flag && st.empty()) cout << "YES\n";
        else cout << "NO\n";
    }

}