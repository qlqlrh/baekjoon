#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N; // N번째 영화 (N < 10,000)
	cin >> N;

	int num = 666;
	int cnt = 0;
	while (true) {
		string s = to_string(num);
		if (s.find("666") != string::npos) {
			cnt++;
		}
		if (cnt == N) {
			cout << num;
			break;
		}
		num++;
	}
}