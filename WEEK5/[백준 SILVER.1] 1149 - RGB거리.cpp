// [백준 SILVER.1] 1149 - RGB거리
// https://www.acmicpc.net/problem/1149

#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    
    int N;
    int r, g, b;
    
    cin >> N;

    int DP[N][3] = { 0, };
    for(int i = 0; i < N; i++) {
        cin >> r >> g >> b;
        
        DP[i][0] = r;
        DP[i][1] = g;
        DP[i][2] = b;
    }
    
    for(int i = 1; i < N; i++) {
        DP[i][0] = min(DP[i-1][1] + DP[i][0], DP[i-1][2] + DP[i][0]);
        DP[i][1] = min(DP[i-1][0] + DP[i][1], DP[i-1][2] + DP[i][1]);
        DP[i][2] = min(DP[i-1][0] + DP[i][2], DP[i-1][1] + DP[i][2]);
    }
    
    if (DP[N-1][0] > DP[N-1][1]) {
        cout << min(DP[N-1][1], DP[N-1][2]);
    } else {
        cout << min(DP[N-1][0], DP[N-1][2]);
    }
    
    return 0;
}
