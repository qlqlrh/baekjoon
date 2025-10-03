#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int arr[10] = {0,};
	string N; // 다솜의 방 번호 (N < 1,000,000)
	cin >> N;
	
	for (char num : N) {
		int n = num - '0';
		if (n == 9) arr[6]++;
		else		    arr[n]++;
	}
	
	if (arr[6] % 2 == 0) arr[6] /= 2;
	else                 arr[6] = arr[6] / 2 + 1;
	
	int result = 0;
	for (int i = 0; i < 9; i++) {
		result = max (result, arr[i]);
	}
	
	cout << result ;
}