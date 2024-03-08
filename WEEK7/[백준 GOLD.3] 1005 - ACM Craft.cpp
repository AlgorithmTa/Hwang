// [백준 GOLD.3] 1005 - ACM Craft
// https://www.acmicpc.net/problem/1005

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int T;
int N, K;

void Solve() {
    cin >> N >> K;
    
    int D;
    vector<int> timeD(1001, 0);
    for(int i = 1; i <= N; i++) {
        cin >> D;
        timeD[i] = D;
    }
    
    vector<int> constOrder[1001];
    int howManyRoadsTo[1001] = { 0, };
    int result[1002];
    int X, Y;
    for(int i = 0; i < K; i++) {
        cin >> X >> Y;
        constOrder[X].push_back(Y);
        howManyRoadsTo[Y] += 1;
    }
    
    int W;
    cin >> W;
    
    queue<int> q;
    for(int i = 1; i <= N; i++) {
        if (howManyRoadsTo[i] == 0) {
            q.push(i);
        }
        result[i] = timeD[i];
    }
    
    while(!q.empty()) {
        int current = q.front();
        q.pop();
        
        for(int i = 0; i < constOrder[current].size(); i++) {
            int next = constOrder[current][i];
            howManyRoadsTo[next] -= 1;
            result[next] = max(result[next], result[current] + timeD[next]);
            
            if (howManyRoadsTo[next] == 0) {
                q.push(next);
            }
        }
    }
    
    cout << result[W] << '\n';
}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> T;
    
    for(int i = 0; i < T; i++) {
        Solve();
    }
}