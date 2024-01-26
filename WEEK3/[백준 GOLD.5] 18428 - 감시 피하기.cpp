// [백준 GOLD.5] 18428 - 감시 피하기
// https://www.acmicpc.net/problem/18428

#include <iostream>
#include <vector>

using namespace std;

struct Point {
    int r;
    int c;
};

int N;
char map[6][6];
vector <Point> notTS;
vector<Point> teacherPosition;

bool makeWallAndConditionCheck();
bool canAvoid();

// `notTS`를 대상으로 장애물을 만들 위치를 3중 for문을 통해 고르기
bool makeWallAndConditionCheck() {
    
    int len = notTS.size();
    for(int i = 0; i < len; i++) {
        map[notTS[i].r][notTS[i].c] = 'W';
        for(int j = i + 1; j < len; j++) {
            map[notTS[j].r][notTS[j].c] = 'W';
            for (int k = j + 1; k < len; k++) {
                map[notTS[k].r][notTS[k].c] = 'W';
                if (canAvoid()){
                    return true;
                    
                }
                map[notTS[k].r][notTS[k].c] = 'X';
            }
            map[notTS[j].r][notTS[j].c] = 'X';
        }
        map[notTS[i].r][notTS[i].c] = 'X';
    }
    
    return false;
}

// 선생님의 위치로부터 상하좌우 방향으로 학생이 보이지 않는지 판별하기
bool canAvoid() {
    for(int i = 0; i < teacherPosition.size(); i++) {
        Point tP = teacherPosition[i];
        // 상
        for(int j = tP.r - 1; j >= 0; j--) {
            if(map[j][tP.c] == 'S') {
                return false;
            } else if(map[j][tP.c] == 'W') {
                break;
            }
        }
        
        // 하
        for(int j = tP.r + 1; j < N; j++) {
            if(map[j][tP.c] == 'S') {
                return false;
            } else if(map[j][tP.c] == 'W') {
                break;
            }
        }
        
        // 좌
        for(int j = tP.c - 1; j >= 0; j--) {
            if(map[tP.r][j] == 'S') {
                return false;
            } else if(map[tP.r][j] == 'W') {
                break;
            }
        }
        
        // 우
        for(int j = tP.c + 1; j < N; j++) {
            if(map[tP.r][j] == 'S') {
                return false;
            } else if(map[tP.r][j] == 'W') {
                break;
            }
        }
    }
    return true;
}

int main()
{
    cin >> N;
    
    int idx = 0;
    Point temp;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'X') {
                temp.r = i;
                temp.c = j;
                notTS.push_back(temp);
            } else if (map[i][j] == 'T') {
                temp.r = i;
                temp.c = j;
                teacherPosition.push_back(temp);
            }
        }
    }
    
    if (makeWallAndConditionCheck() == true) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    
    return 0;
}
