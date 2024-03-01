// [백준 GOLD.4] 1753 - 최단경로
// https://www.acmicpc.net/problem/1753

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int V, E, K;


int main()
{
    cin >> V >> E >> K;
    
    int dist[V+1];
    vector<pair<int, int>> vec[V+1]; // pair<거리, 목적지>
    
    for(int i = 0; i <= V; i++) {
        dist[i] = 100000000;
    }
    
    dist[K] = 0; // 시작위치
    
    int u, v, w;
    for(int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        vec[u].push_back({w, v});
    }
    
    // pair<거리, 목적지>
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, K});
    
    while(!pq.empty()) {
        pair<int, int> current = pq.top();
        pq.pop();
        
        for(int i = 0; i < vec[current.second].size(); i++) {
            pair<int, int> next = vec[current.second][i];
            
            if (dist[next.second] > current.first + next.first) {
                dist[next.second] = current.first + next.first;
                pq.push({dist[next.second], next.second});
            }
        }
    }
    
    for(int i = 1; i <= V; i++) {
        if (dist[i] == 100000000) {
            cout << "INF\n";
        } else {
            cout << dist[i] << '\n';
        }
    }
}