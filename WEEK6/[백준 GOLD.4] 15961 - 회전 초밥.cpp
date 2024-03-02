// [백준 GOLD.4] 15961 - 회전 초밥
// https://www.acmicpc.net/problem/15961

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, d, k, c;
    
    cin >> N >> d >> k >> c;
    
    int num;
    vector<int> v;
    for(int i = 0; i < N; i++) {
        cin >> num;
        v.push_back(num);
    }
    
    unordered_map<int, int> m;
    for(int i = 0; i < k-1; i++) {
        m[v[i]] += 1;
    }
    
    int startPos = 0;
    int endPos = k - 1;
    int result = 0;
    for(int i = 0; i < N; i++) {
        int deleteOne = v[startPos];
        int current = v[endPos % N];
        
        m[current] += 1;
        
        int mSize = m.size();
        
        if (m.find(c) == m.end()) {
            result = max(result, mSize + 1);
        } else {
            result = max(result, mSize);
        }
        
        m[deleteOne] -= 1;
        if (m[deleteOne] == 0) {
            m.erase(deleteOne);
        }
        startPos += 1;
        endPos += 1;
    }
    
    cout << result;
}