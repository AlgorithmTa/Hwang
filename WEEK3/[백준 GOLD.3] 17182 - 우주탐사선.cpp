// [백준 GOLD.3] 17182 - 우주탐사선
// https://www.acmicpc.net/problem/17182

#include <iostream>

using namespace std;

int N, K;
int map[10][10] = { 0, };
int result = 1e6;
bool visited[10] = { false, };

void dfs(int current, int dist, int counter) {
    if (result < dist) {
        return;
    }
    
    if (counter == N) {
        result = min(result, dist);
        return;
    }
    
    for(int i = 0; i < N; i++) {
        if (!visited[i]) {
            visited[i] = true;
            dfs(i, dist + map[current][i], counter + 1);
            visited[i] = false;
        }
    }
}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> K;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }
    
    visited[K] = true;
    
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (map[i][j] > map[i][k] + map[k][j]) {
                    map[i][j] = map[i][k] + map[k][j];
                }
            }
        }
    }
    
    dfs(K, 0, 1);
    cout << result;
    
    return 0;
}