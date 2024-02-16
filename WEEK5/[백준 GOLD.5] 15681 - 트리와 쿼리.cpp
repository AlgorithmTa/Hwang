// [백준 GOLD.5] 15681 - 트리와 쿼리
// https://www.acmicpc.net/problem/15681

#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Node {
    int parent;
    vector<int> childs;
};

int N, R, Q;
vector<vector<int>> v;
map<int, Node> m;

int DP[100001] = { 0, };

void makeTree(int currentNode, int parent) {
    for(int i = 0; i < v[currentNode].size(); i++) {
        if (v[currentNode][i] != parent) {
            m[currentNode].childs.push_back(v[currentNode][i]);
            m[v[currentNode][i]].parent = currentNode;
            makeTree(v[currentNode][i], currentNode);
        }
    }
}

void countSubtreeNodes(int currentNode) {
    DP[currentNode] = 1;
    for(int i = 0; i < m[currentNode].childs.size(); i++) {
        countSubtreeNodes(m[currentNode].childs[i]);
        DP[currentNode] += DP[m[currentNode].childs[i]];
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> R >> Q;
    v = vector<vector<int>>(N + 1);

    int U, V;
    for(int i = 0; i < N - 1; i++) {
        cin >> U >> V;
        v[U].push_back(V);
        v[V].push_back(U);
    }

    makeTree(R, -1);
    countSubtreeNodes(R);

    int num;
    for(int i = 0; i < Q; i++) {
        cin >> num;
        cout << DP[num] << '\n';
    }
}