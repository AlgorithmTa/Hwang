// [백준 GOLD.5] 1916 - 최소비용 구하기
// https://www.acmicpc.net/problem/1916 : 45

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<pair<int, int>> v[1001];
int startP, endP, dis;
int targetStart, targetEnd;
int DP[1001];

void dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, targetStart});

    while(!pq.empty()) {
        pair<int, int> current = pq.top();
        pq.pop();

        // 이미 기록된 비용이 최소라면 continue 처리
        if (DP[current.second] < current.first) {
            continue;
        }

        for(int i = 0; i < v[current.second].size(); i++) {
            pair<int, int> next = v[current.second][i];

            int tempCost = next.first + DP[current.second];

            // 현재 기록된 비용보다 현재 도시(current.second)를 지나는게 비용이 더 적다면
            if (DP[next.second] > tempCost) {
                DP[next.second] = tempCost;
                pq.push({DP[next.second], next.second});
            }
        }
    }
}

int main() {
    cin >> N >> M;

    for(int i = 0; i < M; i++) {
        cin >> startP >> endP >> dis;
        v[startP].push_back({dis, endP});
    }

    cin >> targetStart >> targetEnd;

    for(int i = 0; i <= N; i++) {
        DP[i] = 1000000000;
    }
    DP[targetStart] = 0;

    dijkstra();

    cout << DP[targetEnd];
}