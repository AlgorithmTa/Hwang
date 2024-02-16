// [백준 SILVER.1] 15723 - n단 논법
// https://www.acmicpc.net/problem/15723

#include <iostream>
#include <string>
#include <map>

using namespace std;
map<char, char> m;

void DFS(int current, int end) {
    if (m.find(current) == m.end()) {
        cout << "F\n";
        return;
    }
    
    if (m[current] == end) {
        cout << "T\n";
        return;
    } else {
        DFS(m[current], end);
    }
    
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    
    int n;
    string s;
    
    cin >> n;
    cin.ignore();
    for(int i = 0; i < n; i++) {
        getline(cin, s);
        char start = s[0];
        char end = s[s.size()-1];
        m[start] = end;
    }
    
    int m;
    cin >> m;
    cin.ignore();
    for(int i = 0; i < m; i++) {
        getline(cin, s);
        char start = s[0];
        char end = s[s.size()-1];
        
        DFS(start, end);
    }
    return 0;
}