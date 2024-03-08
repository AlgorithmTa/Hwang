// [백준 GOLD.4] 9252 - LCS 2
// https://www.acmicpc.net/problem/9252

#include <iostream>
#include <string>

using namespace std;

int dp[1001][1001] = { 0, };

string s1, s2;
string resultS = "";

int main()
{
    cin >> s1 >> s2;
    
    for(int i = 0; i <= 1000; i++) {
        for(int j = 0; j <= 1000; j++) {
            dp[i][j] = 0;
        }
    }
    
    for(int i = 1; i <= s1.size(); i++) {
        for(int j = 1; j <= s2.size(); j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i-1][j-1]+1;
            } else {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    
    int endIdx = s2.size();
    for(int r = s1.size(); r >= 1; r--) {
        for(int c = endIdx; c >= 1; c--) {
            if (dp[r][c] == dp[r-1][c]) {
                endIdx = c;
                break;
            } else if (dp[r][c] == dp[r][c-1]) {
                continue;
            } else {
                resultS = s1[r-1] + resultS;
            }
        }
    }

    cout << dp[s1.size()][s2.size()] << '\n';
    cout << resultS;
}