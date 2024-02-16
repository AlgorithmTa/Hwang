// [백준 SILVER.2] 1699 - 제곱수의 합
// https://www.acmicpc.net/problem/1699

#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int dp[100001];
    for(int i = 0; i <= N; i++) {
        dp[i] = i;
    }
    
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j*j <= i; j++)
        {
            // dp[i] : 숫자 i를 만들기 위해 최소한으로 쓰일 수 있는 제곱수의 수
            // dp[i - (j*j)] : 숫자 i에서 j*j 를 뺀 수를 만들기 위해 사용되는 제곱수의 수
            // dp[i - (j*j)]에서 +1이 들어가는 이유는 j*j 제곱수가 한 번 사용되기 때문
            dp[i] = min(dp[i], dp[i-j*j]+1);
        }
    }
    cout << dp[N];
}