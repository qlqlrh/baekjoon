#include <bits/stdc++.h>

using namespace std;


string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> cnt;
    
    for (auto& name: participant)
        cnt[name]++;
    
    for (auto& name: completion)
        cnt[name]--;
    
    for (auto& [name, c]: cnt) {
        if (c > 0)
            return name;
    }
}