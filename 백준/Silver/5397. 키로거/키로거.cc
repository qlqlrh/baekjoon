#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) { // t번 반복
		string inp;
		cin >> inp;

		list<char> pw;
		auto cursor = pw.begin();

		for (char c : inp) {
			if (c == '-') { // 백스페이스 : 커서 앞 문자 삭제 + 커서 뒤로 이동
				if (cursor != pw.begin()) {
					cursor--;
					cursor = pw.erase(cursor);
				}
			}
			else if (c == '<') { // 왼쪽 화살표 : 커서 앞으로 이동
				if (cursor != pw.begin()) {
					cursor--;
				}
			}
			else if (c == '>') { // 오른쪽 화살표 : 커서 뒤로 이동
				if (cursor != pw.end()) {
					cursor++;
				}
			}
			else { // 문자열 입력 : 문자 추가 + 커서 뒤로 이동
				cursor = pw.insert(cursor, c);
				cursor++;
			}
		}

		for (char c : pw) {
			cout << c;
		}
		cout << '\n';
	}
}