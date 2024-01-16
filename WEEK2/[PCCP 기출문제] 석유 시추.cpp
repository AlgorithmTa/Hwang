// [PCCP 기출문제] 석유 시추
// https://school.programmers.co.kr/learn/courses/30/lessons/250136

#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

int dc[4] = {0, 0, -1, 1};
int dr[4] = {-1, 1, 0, 0};
int rSize;
int cSize;
int depth = 1;

bool visited[501][501] = { false };

vector<vector<int>> maps;
map<int, int> oilArea;

void BFS(int r, int c) {
    int oilAreaSize = 0;
    
    queue<pair<int, int>> q;
    q.push({r, c});
    
    maps[r][c] = depth;
    visited[r][c] = true;
    
    while(!q.empty()) {
        int currentR = q.front().first;
        int currentC = q.front().second;
        oilAreaSize += 1;
        q.pop();
        
        // 상하좌우 탐색
        for(int i = 0; i < 4; i++) {
            int tr = currentR + dr[i];
            int tc = currentC + dc[i];
            
            if (tr < 0 || tr >= rSize || tc < 0 || tc >= cSize) // 범위값 판단
                continue;
            else if (visited[tr][tc]) // 방문 여부
                continue;
            else if (maps[tr][tc] == 0) // 석유 유무 여부
                continue;
            
            maps[tr][tc] = depth;
            visited[tr][tc] = true;
            q.push({tr, tc});
        }
    }
    oilArea[depth] = oilAreaSize; // depth번째 석유 시추 가능 영역의 사이즈는 oilAreaSize
    depth += 1;
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    
    // 행렬 사이즈 저장
    rSize = land.size();
    cSize = land[0].size();
    maps = land;
    for(int i = 0; i < rSize; i++) {
        for(int j = 0; j < cSize; j++) {
            // 방문하지 않은 석유 시추 가능 영역이라면 BFS 수행
            if(visited[i][j] == false && maps[i][j] == 1) {
                BFS(i, j);
            }
        }
    }
    
    // 각각의 열에 시추 파이프를 내릴 것이기 때문에 cSize를 기준으로 for문 수행
    // 중복을 허용하지 않는 set을 사용해 각 열의 시추 가능 영역의 번호를 넣는다.
    for(int i = 0; i < cSize; i++) {
        int totalOilAreaSize = 0;
        set<int> s;
        for(int j = 0; j < rSize; j++) {
            s.insert(maps[j][i]);
        }
        
        // 현재 열에서 시추 영역의 전체 사이즈 추출
        for (auto it : s) {
            totalOilAreaSize += oilArea[it];
        }
        answer = max(answer, totalOilAreaSize);
    }
    return answer;
}