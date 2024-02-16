// [2022 KAKAO TECH INTERNSHIP] 행렬과 연산
// https://school.programmers.co.kr/learn/courses/30/lessons/118670

#include <string>
#include <vector>
#include <deque>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> rc, vector<string> operations) {
    
    deque<int> col_left;
    deque<int> col_right;

    int r = rc.size();
    int c = rc[0].size();
    int startRowIndex = 0;
    
    // 최좌측, 최우측 행렬 분할
    for(int i = 0; i < r; i++) {
        col_left.push_back(rc[i][0]);
        col_right.push_back(rc[i][c-1]);
    }
    
    deque<int> rows[r];
    
    // 좌측 우측 열을 분리한 중앙부 열로 구성된 행 초기화
    for(int i = 0; i < r; i++) {
        for(int j = 1; j < c-1; j++) {
            rows[i].push_back(rc[i][j]);
        }
    }
    
    for (auto operation : operations) {
        if (operation[0] == 'S') { // ShiftRow

            // 좌우 행렬 deque의 front를 back으로 갱신 & back 제거
            int left_back = col_left.back();
            col_left.push_front(left_back);
            col_left.pop_back();
            
            int right_back = col_right.back();
            col_right.push_front(right_back);
            col_right.pop_back();
            
            // 가장 첫 행의 인덱스만 갱신하기
            if (startRowIndex == 0) {
                startRowIndex = r - 1;
            } else {
                startRowIndex -= 1;
            }
        } else if (operation[0] == 'R') { // Rotation

            // 시계 방향으로 각각의 front(back) 붙이기
            int endRowIndex = (startRowIndex + r - 1) % r;
            rows[startRowIndex].push_front(col_left.front());
            col_right.push_front(rows[startRowIndex].back());
            rows[endRowIndex].push_back(col_right.back());
            col_left.push_back(rows[endRowIndex].front());
            
            // 옮긴 front(back) 제거
            col_left.pop_front();
            rows[startRowIndex].pop_back();
            col_right.pop_back();
            rows[endRowIndex].pop_front();
        }
    }
    
    vector<vector<int>> answer(r);
    for(int i = 0; i < r; i++) {
        int start = col_left.front();
        int end = col_right.front();
        
        col_left.pop_front();
        col_right.pop_front();
        
        answer[i].push_back(start);
        
        int rowIndex = (startRowIndex + i) % r;
        for(int j = 0; j < c - 2; j++) {
            answer[i].push_back(rows[rowIndex].front());
            rows[rowIndex].pop_front();
        }
        answer[i].push_back(end);
    }
    return answer;
}