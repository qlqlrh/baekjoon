#include <iostream>
#include <unordered_set>

using namespace std;

int N, M;
unordered_set<int> mySet;

int main () {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    for (int i = 0; i < N; i++) { // N번 반복
        int num;
        cin >> num;
        mySet.insert(num);
    }

    cin >> M;
    for (int i = 0; i < M; i++) { // M번 반복
        int num;
        cin >> num;
        if (mySet.count(num)) {
            cout << "1\n";
        }
        else {
            cout << "0\n";
        }
    }

}