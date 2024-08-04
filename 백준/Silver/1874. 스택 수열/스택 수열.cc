#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int N; // 1 ~ 100,000
string result;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    stack<int> myStack;
    int index = 0;
    for (int i = 0; i < N; i++) {
        int num = 0;
        cin >> num;

        if (index < num) {
            // push 해야 함
            for (int j = index; j < num; j++) {
                myStack.push(j + 1);
                result += "+\n";
            }
            index = num;
        }

        if (myStack.top() != num) {
            cout << "NO\n";
            return 0;
        }
        else {
            myStack.pop();
            result += "-\n";
        }
    }

    cout << result << endl;
}