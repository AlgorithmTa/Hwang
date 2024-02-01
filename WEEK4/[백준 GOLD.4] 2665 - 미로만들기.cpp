// [백준 GOLD.4] 2665 - 미로만들기
// https://www.acmicpc.net/problem/2665

#include <iostream>
#include <queue>

using namespace std;

struct Position {
    int r;
    int c;
    
    Position(int _r, int _c) : r(_r), c(_c) { }
};

int N;
int arr[51][51] = { 0, };
int visited[51][51];

// 상 하 좌 우
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void stringToInt(string s, int r) {
    for(int i = 0; i < s.size(); i++) {
        arr[r][i] = s[i] - '0';
    }
}

void Solve() {
    queue<Position> q;
    q.push(Position(0, 0));
    
    for(int i = 0; i < 51; i++) {
        for(int j = 0; j < 51; j++) {
            visited[i][j] = 251;
        }
    }
    
    visited[0][0] = 0;
    
    while(!q.empty()) {
        Position current = q.front();
        q.pop();
        
        for(int i = 0; i < 4; i++) {
            int tr = current.r + dr[i];
            int tc = current.c + dc[i];
                
            if (tr < 0 || tc < 0 || tr >= N || tc >= N) {
                continue;
            }
            
            // deltaVal == 1 : 방의 색상을 바꾼다
            // deltaVal == 0 : 방의 색상을 바꾸지 않는다
            int deltaVal = 1 - arr[tr][tc];
            
            // 가야하는 지점(tr, tc) 지점의 값이 현재 위치(r, c)에서 deltaVal을 더한 것보다 큰 경우
            // 가야하는 지점이 색상 변경이 더 많이 일어나야하는 경우
            // 현재 지점까지의 (최소) 색상 변경 횟수 + deltaVal로 (tr, tc)의 값을 치환한다.
            if(visited[tr][tc] > visited[current.r][current.c] + deltaVal) {
                visited[tr][tc] = visited[current.r][current.c] + deltaVal;
                q.push(Position(tr, tc));
            }
            
        }
    }
}

int main()
{
    cin >> N;
    
    string temp;
    for(int i = 0; i < N; i++) {
        cin >> temp;
        stringToInt(temp, i);
    }
    
    Solve();
    cout << visited[N-1][N-1];
    
    return 0;
}
