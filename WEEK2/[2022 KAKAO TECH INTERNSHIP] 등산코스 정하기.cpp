// [2022 KAKAO TECH INTERNSHIP] 등산코스 정하기
// https://school.programmers.co.kr/learn/courses/30/lessons/118669

#include <string>
#include <vector>
#include <queue>

#define LEN 50001
#define MAX 10000001

using namespace std;

bool isSummit[LEN] = { false }; // 산봉우리 판별
int dist[LEN]; // ex) dist[n]: 노드 n으로 이동할 때 주변 노드에서 가장 비용이 많이 발생하는 경우
vector<pair<int,int>> nodeV[LEN]; // dijkstra 수행을 위한 node

void fillSummitAndDist(int n, vector<int> summits) {
    for(auto summit : summits) {
            isSummit[summit] = true;
    }
    fill(dist, dist + n + 1, MAX);
}
void makeNodeV(vector<vector<int>> paths) {
    for(auto path : paths) {
        int node1 = path[0];
        int node2 = path[1];
        int timeTaken = path[2];
        
        nodeV[node1].push_back({node2, timeTaken});
        nodeV[node2].push_back({node1, timeTaken});
    }
}

void dijkstra(vector<int> gates) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    // 출입구를 pq에 넣는다
    for(auto gate : gates) {
        dist[gate] = 0;
        pq.push({dist[gate], gate});
    }
    
    // pq가 빌 때까지 (dijkstra의 수행이 끝나 각 노드 간의 최소 intensity를 구하기까지 수행)
    while(!pq.empty()) {
        int currentNode = pq.top().second; // second: 방문한 노드
        int currentIntensity = pq.top().first; // first: 방문한 노드의 intensity
        pq.pop();
        
        // dist의 값과 node의 실제 intensity가 일치하지 않는 경우
        // pq를 통한 Dijkstra 알고리즘에 의해 특정 노드의 dist값의 갱신이 이루어진 경우에 해당
        if (dist[currentNode] != currentIntensity) {
            continue;
        }

        for(auto node: nodeV[currentNode]) {
            int nextNode = node.first;
            int nodeIntensity = node.second;
            
            // nextNode의 dist값이 max(currentNode의 dist값, current - next 간의 intensity) 보다 작거나 같다면 continue
            // 특정 정점까지의 루트에서 관측된 intensity가 '전체 노드를 기준으로 보았을 때에는 작으면서도, 각각의 등산 루트에서는 가장 큰 값'을 요구하기 때문에
            // 아래와 같은 연산을 수행함
            if (dist[nextNode] <= max(dist[currentNode], nodeIntensity))
                continue;
            dist[nextNode] = max(dist[currentNode], nodeIntensity);
            
            // 산봉우리가 아니라면 pq에 추가
            // 산봉우리를 두 번 이상 방문하는 일을 만들지 않기 위함
            if (!isSummit[nextNode]) {
                pq.push({dist[nextNode], nextNode});
            }
        }
    }
}

vector<int> getAnswer(vector<int> summits) {
    vector<int> answer;

    int ans = summits[0];

    // 산봉우리까지의 경로에서 가장 dist가 작은 값을 찾는다
    for(auto summit : summits) {
        if(dist[summit] < dist[ans]) {
            ans = summit;
        } else if (dist[summit] == dist[ans] && summit < ans) {
            ans = summit;
        }
    }
    
    answer.push_back(ans);
    answer.push_back(dist[ans]);

    return answer;
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer;
    
    fillSummitAndDist(n, summits);
    makeNodeV(paths);
    dijkstra(gates);
    answer = getAnswer(summits);
    
    return answer;
}