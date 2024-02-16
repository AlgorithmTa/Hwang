// [백준 SILVER.3] 17413 - 단어 뒤집기2
// https://www.acmicpc.net/problem/17413

#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

stack<char> sta;

string reverse(string temp) {
    reverse(temp.begin(), temp.end());
    return temp;
}


string getStr() {
    string temp;
    while(!sta.empty()) {
        temp += sta.top();
        sta.pop();
    }
    return temp;
}

bool isInTag = false;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    
    
    string s;
    getline(cin, s);
    
    for(int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            if (isInTag == true) {
                sta.push(s[i]);
            } else {
                cout << getStr();
                cout << ' ';
            }
        } else {
            if (s[i] == '<') {
                isInTag = true;
                cout << getStr();
            }
            sta.push(s[i]);
            if (s[i] == '>') {
                cout << reverse(getStr());
                isInTag = false;
            }
        }
    }
    if (s[s.size() - 1] == '>') {
        cout << reverse(getStr());
    } else {
        cout << getStr();
    }
    return 0;
}