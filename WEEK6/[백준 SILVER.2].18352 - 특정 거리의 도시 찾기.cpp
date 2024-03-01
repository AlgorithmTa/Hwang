// [백준 SILVER.2].18352 - 특정 거리의 도시 찾기
// https://www.acmicpc.net/problem/18352

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, K, X;


int main()
{
    cin >> N >> M >> K >> X;
    
    int dist[N+1];
    vector<int> v[N+1];
    int a, b;
    
    for(int i = 0; i <= N; i++) {
        dist[i] = 100000000;
    }
    
    dist[X] = 0;
    
    for(int i = 0; i < M; i++) {
        cin >> a >> b;
        v[a].push_back(b);
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, X});
    
    while(!pq.empty()) {
        pair<int, int> current = pq.top();
        pq.pop();
        
        for(int i = 0; i < v[current.second].size(); i++) {
            int next = v[current.second][i];
            
            if (dist[next] > current.first + 1) {
                dist[next] = current.first + 1;
                pq.push({dist[next], next});
            }
        }
    }
    
    int counter = 0;
    for(int i = 1; i <= N; i++) {
        if (i == X) continue;
        if (dist[i] == K) {
            cout << i << '\n';
            counter += 1;
        }
    }
    
    if (counter == 0) {
        cout << -1;
    }
}