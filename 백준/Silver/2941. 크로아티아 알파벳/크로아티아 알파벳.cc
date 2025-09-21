#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<string> v = // 변경된 크로아티아 알파벳
        {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

    string s; // 크로아티아 알파벳
    cin >> s;

    int cnt = 0;
    int i = 0;
    while (i < s.length()) {
        string sub = s.substr(i, 2);
        if ((sub == "dz") && (s.substr(i, 3) == "dz="))
            sub = "dz=";
        if (find(v.begin(), v.end(), sub) == v.end()) { // 못찾음
            i += 1;
            cnt++;
        } else { // 찾음
            cnt++;
            i = (sub == "dz=") ? i + 3 : i + 2;
        }
    }

    cout << cnt;

    return 0;
}