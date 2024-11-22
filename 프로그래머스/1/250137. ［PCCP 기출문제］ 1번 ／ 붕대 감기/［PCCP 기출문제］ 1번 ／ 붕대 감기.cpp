#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int leftHealth = health;
    
    // bandage : [시전 시간, 초당 회복량, 추가 회복량]
    // health  : 최대 체력
    // attacks : [[공격 시간, 피해량], [공격 시간, 피해량], ...]
    
    int cycle    = bandage[0];
    int secPlus  = bandage[1];
    int morePlus = bandage[2];
    
    int lastAttackTime = attacks.back()[0];
    int serialSuccess = 0; // 최댓값 : cycle
    
    vector<int> attackTimes;
    vector<int> attackVolumns;
    for (auto attack : attacks) {
        // attack : [공격 시간, 피해량]
        attackTimes.push_back(attack[0]);
        attackVolumns.push_back(attack[1]);   
    }
    
    int i = 0;
    for (int t = 1; t <= lastAttackTime; t++) {
        if (t == attackTimes[i]) { // 공격 시간
            leftHealth -= attackVolumns[i++];
            serialSuccess = 0;
            if (leftHealth <= 0) {
                return -1;
            }
        }
        else { // 체력 회복
            serialSuccess += 1;
            leftHealth += secPlus;
            if (serialSuccess >= cycle) {
                leftHealth += morePlus;
                serialSuccess = 0;
            }
            if (leftHealth >= health) {
                leftHealth = health;
            }
        }
        cout << t << "초 -> " << leftHealth << endl;
    }
    
    return leftHealth; // 남은 체력 리턴, 죽는 경우라면 -1 리턴
}