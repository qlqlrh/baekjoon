#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	list<int> circle;
	for (int i = 0; i < N; i++) {
		circle.push_back(i + 1);
	}

	vector<int> result;
	auto first = circle.begin();
	while(!circle.empty()) {
		// K번째 값 삭제
		auto it = circle.begin();
		advance(it, (K - 1) % circle.size());
		result.push_back(*it); // 삭제 순서 저장
		first = circle.erase(it); // 12{4}567

		if (circle.empty()) break;

		// 순서 재정렬
		circle.splice(circle.end(), circle, circle.begin(), first);
	}

	// 결과 출력
	cout << "<";
	for (int i = 0; i < N; i++) {
		if (i == N -1) cout << result[i];
		else cout << result[i] << ", ";
	}
	cout << ">\n";
}