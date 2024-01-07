#include <iostream>
#include <queue>
#include <string>
#include <set>
using namespace std;

// * 길이가 짧은 것부터
// * 길이가 같으면 사전 순으로 정렬

struct cmp {
    bool operator()(string front, string back) {
        if (front.size() == back.size())
            return front > back;
        return front.size() > back.size();
    }
};

int N; // 단어의 개수
set<string> tmp; // 중복 제거용
priority_queue<string, vector<string>, cmp> dic; // 최종 정렬

int main() {
    cin >> N;

    string word;
    for (int i = 0; i < N; i++) {
        cin >> word;
        tmp.insert(word);
    }

    for (string word : tmp)
        dic.push(word);

    while (!dic.empty()) {
        string top = dic.top();
        dic.pop();
        cout << top << endl;
    }
}