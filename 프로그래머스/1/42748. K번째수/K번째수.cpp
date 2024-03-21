#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#define allout(MSG, A) cout << MSG << " : "; for (auto w : A) cout << w << " ";
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    auto it = array.begin();
    
    for (vector<int> command : commands) { // command는 vector
        int i = command[0];
        int j = command[1];
        int k = command[2];
        
        vector<int> sub_vec (it + i - 1, it + j);
        sort(sub_vec.begin(), sub_vec.end());
        // allout("sub_vec", sub_vec);
        answer.push_back(sub_vec[k-1]);
    }
    // allout("answer", answer);
    return answer;
}