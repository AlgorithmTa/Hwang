// [백준 SILVER.4] 1158 - 요세푸스 문제
// https://www.acmicpc.net/problem/1158

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

queue<int> q;
vector<int> v;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    
    int N, K;
    cin >> N >> K;
    
    for(int i = 1; i <= N; i++) {
        q.push(i);
    }
    int counter = 1;
    int temp;
    while(!q.empty()) {
        if (counter == K) {
            counter = 1;
            v.push_back(q.front());
            q.pop();
        } else {
            counter += 1;
            temp = q.front();
            q.pop();
            q.push(temp);
        }
    }
    
    for(int i = 0; i < v.size(); i++) {
        if (i == 0) {
            cout <<"<";
        }
        cout << v[i];
        if (i == v.size() - 1) {
            cout << ">";
        } else {
            cout << ", ";
        }
    }
    return 0;
}