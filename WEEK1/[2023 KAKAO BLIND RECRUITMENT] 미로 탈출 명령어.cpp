// [2023 KAKAO BLIND RECRUITMENT] 미로 탈출 명령어
// https://school.programmers.co.kr/learn/courses/30/lessons/150365

#include <string>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
    int x;
    int y;
};

Point startP;
Point endP;

// 하 좌 우 상
int dx[4] = { 1, 0, 0, -1 };
int dy[4] = { 0, -1, 1, 0 };
char direction[4] = { 'd', 'l', 'r', 'u' };

string route;
bool flag = false;

void DFS(int n, int m, int counter, int k, Point pos, string currentRoute) {
    
    if (flag == true) {
        return;
    }
    
    if (k - counter < abs(pos.x - endP.x) + abs(pos.y - endP.y)) {
        return;
    }
    
    if (counter == k) {
        if ((pos.x == endP.x) && (pos.y == endP.y)) {
            route = currentRoute;
            flag = true;
        }
        return;
    }
    
    for(int i = 0; i < 4; i++) {
        int tx = dx[i];
        int ty = dy[i];
        
        char currentDir = direction[i];
        
        Point temp = pos;
        temp.x += tx;
        temp.y += ty;
        
        if (temp.x < 1 || temp.x > n || temp.y < 1 || temp.y > m)
            continue;
        
        DFS(n, m, counter + 1, k, temp, currentRoute + currentDir);
    }
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";
    
    startP.x = x;
    startP.y = y;
    
    endP.x = r;
    endP.y = c;
    
    int dist = abs(x - r) + abs(y - c);
    if ((k - dist) % 2 != 0 || dist > k) {
        route = "impossible";
    } else {
        DFS(n, m, 0, k, startP, "");
    }
    answer = route;
    return answer;
}