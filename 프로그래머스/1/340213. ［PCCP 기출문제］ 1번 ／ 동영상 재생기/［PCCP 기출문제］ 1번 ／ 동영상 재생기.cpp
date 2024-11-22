#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <iomanip> // setw, setfill

using namespace std;

void checkOpening(int& currenTime, int total_op_start, int total_op_end) {
    // 오프닝 건너뛰기
    if (currenTime <= total_op_end && currenTime >= total_op_start) {
        currenTime = total_op_end;
    }
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    
    // 형 변환
    int video_len_min = stoi(video_len.substr(0, 2));
    int video_len_sec = stoi(video_len.substr(3, 2));
    int total_video_len = video_len_min * 60 + video_len_sec; // 초 단위
    
    int pos_min = stoi(pos.substr(0, 2));
    int pos_sec = stoi(pos.substr(3, 2));
    int total_pos = pos_min * 60 + pos_sec; // 초 단위
    
    
    int op_start_min = stoi(op_start.substr(0, 2));
    int op_start_sec = stoi(op_start.substr(3, 2));
    int total_op_start = op_start_min * 60 + op_start_sec; // 초 단위

    
    int op_end_min = stoi(op_end.substr(0, 2));
    int op_end_sec = stoi(op_end.substr(3, 2));
    int total_op_end = op_end_min * 60 + op_end_sec; // 초 단위
    
    
    checkOpening(total_pos, total_op_start, total_op_end);
        
    // 명령어 수행
    for (string command : commands) {
        if (command == "prev") {
            total_pos -= 10;
            if (total_pos < 0) {
                total_pos = 0;
            }
            
        }
        else if (command == "next") {
             total_pos += 10;
            if (total_pos > total_video_len) {
                total_pos = total_video_len;
                cout << total_pos << endl;
            }
        }
        checkOpening(total_pos, total_op_start, total_op_end);
    }
    

    
    // 다시 형변환
    ostringstream oss;
    oss << setw(2) << setfill('0') << total_pos / 60 << ":";
    oss << setw(2) << setfill('0') << total_pos % 60;

    answer = oss.str();
    return answer;
}