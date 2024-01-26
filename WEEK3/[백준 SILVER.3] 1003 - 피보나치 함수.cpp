// [백준 SILVER.3] 1003 - 피보나치 함수
// https://www.acmicpc.net/problem/1003

#include <iostream>

using namespace std;

pair<int, int> DP[41] = {{ 0, 0 }};

void fibonacci() {
    // first: zeroCount
    // second: oneCount
    DP[0].first = 1;
    DP[0].second = 0;
    DP[1].first = 0;
    DP[1].second = 1;
    for(int i = 2; i <= 40; i++) {
        DP[i].first = DP[i-1].first + DP[i-2].first;
        DP[i].second = DP[i-1].second + DP[i-2].second;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    
    fibonacci();
    
    int N;
    for(int i = 0; i < T; i++) {
        cin >> N;
        cout << DP[N].first << ' ' << DP[N].second << '\n';
    }
    
    return 0;
}
