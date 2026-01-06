#include <bits/stdc++.h>

using namespace std;

int N; // 포켓몬 개수 (1 ~ 100,000)
int M; // 맞춰야 하는 문제 개수 (1 ~ 100,000)
vector<string> v; // 포켓몬 도감
unordered_map<string, int> unmap;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    // 포켓몬 이름 <=> 번호 매핑
    cin >> N >> M;

    // 1. 포켓몬 정보 입력 받기
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        v.push_back(s);
        unmap[s] = i + 1;
    }

    for (int i = 0; i < M; i++) {
        // 2. 타입 판단
        string s;
        cin >> s;

        // 포켓몬 번호인 경우
        if (isdigit(s[0])) {
            int index = stoi(s);
            cout << v[index-1] << "\n";
        }
        // 포켓몬 이름인 경우
        else {
            cout << unmap[s] << "\n";
        }
    }
}