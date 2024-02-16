// [백준 GOLD.4] 1976 - 여행 가자
// https://www.acmicpc.net/problem/1976

#include <iostream>
#include <vector>

using namespace std;

vector<int> parentV;
vector<int> pathV;

int arr[201][201];

int find(int node) {
    if (node == parentV[node]) {
        return node;
    }
    int temp = find(parentV[node]);
    parentV[node] = temp;
    return temp;
}

void tree_union(int x, int y) {
    x = find(x);
    y = find(y);
    
    if (x == y) {
        return;
    }
    
    if (x < y) {
        parentV[y] = x;
    } else {
        parentV[x] = y;
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    
    parentV = vector<int> (N + 1, 0);
    pathV = vector<int> (M + 1, 0);
    
    for(int i = 0; i <= N; i++) {
        parentV[i] = i;
    }
    
    for(int i = 1; i <= N; i++) {
        for (int j = 1; j<= N; j++) {
            cin >> arr[i][j];
            
            // 연결되어 있다면 Union-Find 수행
            if (arr[i][j] == 1) {
                tree_union(i, j);
            }
        }
    }
    
    for(int i = 1; i <= M; i++) {
        cin >> pathV[i];
    }
    
    for(int i =1; i < M; i++) {
        if(find(pathV[i]) != find(pathV[i + 1])) {
            cout << "NO";
            return 0;
        }
    }
    
    cout << "YES";
    return 0;
}