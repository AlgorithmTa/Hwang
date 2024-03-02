// [백준 GOLD.4] 14267 - 회사 문화 1
// https://www.acmicpc.net/problem/14267

#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> v[100001];
vector<int> compliments;

void DFS(int current) {
    for(int i = 0; i< v[current].size(); i++) {
        int next = v[current][i];
        compliments[next] += compliments[current];
        DFS(next);
    }
}

int main()
{
    cin >> N >> M;
    compliments.assign(N + 1, 0);   
    
    int num;
    for(int i = 1; i <= N; i++) {
        cin >> num;
        if (num == -1) {
            continue;
        }
        
        v[num].push_back(i);
    }
    
    int compNum;
    for(int i = 0; i < M; i++) {
        cin >> num >> compNum;
        compliments[num] += compNum;
    }
    
    DFS(1);
    
    for(int i = 1; i <= N; i++) {
        cout << compliments[i] << ' ';
    }
    return 0;
}
