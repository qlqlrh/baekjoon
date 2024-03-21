#include <string>
#include <vector>
#include <iostream>
#include <algorithm> // rotate
#define allout(MSG, A) cout << MSG << " : "; for (auto w : A) cout << w << " ";

using namespace std;

bool mycmp(const string front, const string back) {
    return (front + back) > (back + front);
}

string solution(vector<int> numbers) {
    // string -> int 함수 : std::stoi(string)
    // int -> string 함수 : std::to_string(int)
    // long 타입으로 설정
        
    string answer = "";
    int SIZE = numbers.size();
    
    vector<string> tempStr;
    for (int i = 0; i < SIZE; i++) {
        tempStr.push_back(to_string(numbers[i]));
    }
    
    sort(tempStr.begin(), tempStr.end(), mycmp);
    // allout("sort", tempStr);
    
    for (auto str : tempStr) {
        answer += str;
    }
        
    if (answer[0] == '0') {
        answer = '0';
    }
    
    return answer;
}