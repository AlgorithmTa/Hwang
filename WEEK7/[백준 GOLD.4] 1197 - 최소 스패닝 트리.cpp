// [백준 GOLD.4] 1197 - 최소 스패닝 트리
// https://www.acmicpc.net/problem/1197

#include <iostream>
#include <queue>

using namespace std;

int V, E;
int A, B, C;
vector<pair<int, int>> v[10001];
bool visited[10001] = { false, };
int result = 0;

int main()
{
    cin >> V >> E;
    
    for(int i = 0; i < E; i++) {
        cin >> A >> B >> C;
        v[A].push_back({C, B});
        v[B].push_back({C, A});
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    pq.push({0, 1});
    
    while(!pq.empty()) {
        pair<int, int> current = pq.top();
        pq.pop();
        
        if (visited[current.second]) {
            continue;
        }
        
        visited[current.second] = true;
        
        result += current.first;
        
        for(int i = 0; i < v[current.second].size(); i++) {
            pair<int, int> next = v[current.second][i];
            
            pq.push(next);
        }
    }
    
    cout <<result;
}
