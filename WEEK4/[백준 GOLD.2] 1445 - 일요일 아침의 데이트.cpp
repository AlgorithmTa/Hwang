// [백준 GOLD.2] 1445 - 일요일 아침의 데이트
// https://www.acmicpc.net/problem/1445

#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct Position {
    int r;
    int c;
    
    Position(int _r, int _c) : r(_r), c(_c) { }
};

struct Compare {
    bool operator()(const pair<pair<int, int>, Position>& p1, const pair<pair<int, int>, Position>& p2) {
        if (p1.first.first != p2.first.first) {
            return p1.first.first > p2.first.first;
        }
        if (p1.first.second != p2.first.second) {
            return p1.first.second > p2.first.second;
        }
        return false;
    }
};

int N, M;
char map[51][51];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int dist[51][51];

Position startPos = Position(0, 0);
Position endPos = Position(0, 0);

int onTrash;
int betweenTrash;

void stringToChar(string s, int r) {
    for(int i = 0; i < s.size(); i++) {
        map[r][i] = s[i];
        if (map[r][i] == 'S') {
            startPos = Position(r, i);
        } else if (map[r][i] == 'F') {
            endPos = Position(r, i);
        }
    }
}

void Solve() {
    
    int onTrashCount = 0;
    int betweenTrashCount = 0;
    
    for(int i = 0; i < 51; i++) {
        for(int j = 0; j < 51; j++) {
            dist[i][j] = -1;
        }
    }
    
    dist[startPos.r][startPos.c] = 0;
    
    priority_queue<pair<pair<int, int>, Position>, vector<pair<pair<int, int>, Position>>, Compare> pq;
    pq.push({{0, 0}, startPos});
    
    while(!pq.empty()) {
        bool findCheck = false;
        
        onTrash = pq.top().first.first;
        betweenTrash = pq.top().first.second;
        Position current = pq.top().second;
        pq.pop();
        
        for(int i = 0; i < 4; i++) {
            Position next = Position(current.r + dr[i], current.c + dc[i]);
            
            if (next.r == endPos.r && next.c == endPos.c) {
                onTrashCount = onTrash;
                betweenTrashCount = betweenTrash;
                findCheck = true;
                break;
            }

            if (next.r < 0 || next.c < 0 || next.r >= N || next.c >= M) {
                continue;
            }

            if (dist[next.r][next.c] != -1) {
                continue;
            }
            
            if (map[next.r][next.c] == 'g') {
                pq.push({{onTrash+1, betweenTrash}, next});
            } else if (map[next.r][next.c] == '.') {
                bool trashCheck = false;
                for(int j = 0; j < 4; j++) {
                    Position nextnext = Position(next.r + dr[j], next.c + dc[j]);
                    
                    if (map[nextnext.r][nextnext.c] == 'g') {
                        trashCheck = true;
                        break;
                    }
                }
                
                if (trashCheck) {
                    pq.push({{onTrash, betweenTrash + 1}, next});
                } else {
                    pq.push({{onTrash, betweenTrash}, next});
                }
            }
            
            dist[next.r][next.c] = dist[next.r][next.c] + 1;
        }
        
        if (findCheck) {
            break;
        }
    }
    
    cout << onTrashCount << ' ' << betweenTrashCount;
}

int main()
{
    cin >> N >> M;
    
    string s;
    for(int i = 0; i < N; i++) {
        cin >> s;
        stringToChar(s, i);
    }
    
    Solve();
    return 0;
}
