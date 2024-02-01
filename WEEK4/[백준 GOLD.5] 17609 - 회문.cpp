// [백준 GOLD.5] 17609 - 회문
// https://www.acmicpc.net/problem/17609

#include <iostream>
#include <string>

using namespace std;

string s;
int isPalindrome(int left, int right, bool firstCall) {
    while (left < right) {
        if (s[left] != s[right]) {
            if (firstCall) {
                if (isPalindrome(left + 1, right, false) == 0 || isPalindrome(left, right - 1, false) == 0) {
                   return 1;
                }   
            }
            return 2;
        }
        
        left += 1;
        right -= 1;
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    
    for(int i = 0; i < T; i++) {
        cin >> s;
        cout << isPalindrome(0, s.size() - 1, true) << '\n';
    }

    return 0;
}
