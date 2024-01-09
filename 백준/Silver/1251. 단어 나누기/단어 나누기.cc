#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// * vector의 slice와 reverse 사용하면 될 듯?
// * 시간 제한이 2초인 걸 보면 전체 경우의 수를 다 생각해야 하는 듯

vector<char> word;
vector<vector<char>> words;

int main() {
    string myString;
    cin >> myString;

    for (char item : myString)
        word.push_back(item);

    for (auto it = word.begin(); it != word.end(); it++) { // break point 1
        for (auto it2 = it + 1; it2 != word.end(); it2++) { // break point2
            vector<vector<char>> myvec;
            vector<char> myvec1(word.begin(), it+1);
            vector<char> myvec2(it+1, it2+1);
            vector<char> myvec3(it2+1, word.end());
            vector<char> tmp;
            myvec.push_back(myvec1);
            myvec.push_back(myvec2);
            myvec.push_back(myvec3);
            if (myvec1.size() && myvec2.size() && myvec3.size()) {
                for (auto it : myvec) { // it : vector<char>
                    reverse(it.begin(), it.end());
                    tmp.insert(tmp.end(), it.begin(), it.end());
                }
                words.push_back(tmp);
            }
        }
    }

    sort(words.begin(), words.end());

    for (auto it : words[0]) { // words[0] : vector<char>
        cout << it;
    }
}