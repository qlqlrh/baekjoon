#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; // 수열의 크기
	cin >> n;

	vector<int> vec;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		vec.push_back(num);
	}

	int x;
	cin >> x;

	set<int> pairs; // x와 수열 각 원소들의 차 => 이 값이 vec에 있어야 됨
	for (int i = 0; i < n; i++) {
		pairs.insert(x - vec[i]);
	}

	int cnt = 0;
	for (int num : vec) {
		if (pairs.find(num) != pairs.end()) {
			cnt++;
		}
	}

	cout << cnt / 2 << endl;
}