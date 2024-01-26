// [백준 SILVER.2] 12891 - DNA 비밀번호
// https://www.acmicpc.net/problem/12891

#include <iostream>
#include <string>
#include <map>

using namespace std;

map<char, int> condition;
map<char, int> current;
char dnaArr[4] = {'A', 'C', 'G', 'T'};

bool canMake() {
    for(int i = 0; i < 4; i++) {
        if (condition[dnaArr[i]] > current[dnaArr[i]]) {
            return false;
        }
    }
    return true;
}

int main()
{
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int S, P;
    int result = 0;
    
    cin >> S >> P;
    
    string s;
    cin >> s;
    
    for(int i = 0; i < P; i++) {
        current[s[i]] += 1;
    }
    
    for(int i = 0; i < 4; i++) {
        cin >> condition[dnaArr[i]];
    }
    
    int lastIdx = S - P;

    //  // 0번째 idx - (P-1)번째 idx가 조건을 만족하는지 판단하기 위함
    if (canMake()) {
        result += 1;
    }
    
    for(int i = 1; i <= lastIdx; i++) {
        char throwChar = s[i - 1];
        current[throwChar] -= 1;
            
        char addChar = s[i + P - 1];
        current[addChar] += 1;
        
        if (canMake()) {
            result += 1;
        }
    }
    
    cout << result;

    return 0;
}