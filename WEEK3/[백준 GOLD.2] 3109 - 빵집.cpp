// [백준 GOLD.2] 3109 - 빵집
// https://www.acmicpc.net/problem/3109

#include <iostream>

using namespace std;

int R, C;
char map[10001][501];
bool visited[10001][501] = { false, };
int result = 0;
int dr[3] = {-1, 0, 1};
bool isFindWay = false;

void dfs(int curDepth, int r, int c) {
    visited[r][c] = true;
    if ((curDepth == C)) {
        isFindWay = true;
        result += 1;
        return;
    }
    
    for(int i = 0; i < 3; i++) {
        int nextR = r + dr[i];
        int nextC = c + 1;
        
        if (nextR < 0 || nextC < 0 || nextR >= R || nextC >= C)
            continue;
        if (map[nextR][nextC] == 'x')
            continue;
        
        if (!visited[nextR][nextC]) {
            visited[nextR][nextC] = true;
            dfs(curDepth + 1, nextR, nextC);
            if (isFindWay) {
                return;
            }
        }
    }
}

int main() {
    
    cin >> R >> C;
    
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cin >> map[i][j];
        }
    }
    
    for(int i = 0; i < R; i++) {
        dfs(1, i, 0);
        isFindWay = false;
    }
    
    cout << result;
    return 0;
}