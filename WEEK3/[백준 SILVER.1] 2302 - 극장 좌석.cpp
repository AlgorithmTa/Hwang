// [백준 SILVER.1] 2302 - 극장 좌석
// https://www.acmicpc.net/problem/2302

#include <iostream>
#define LEN 41

using namespace std;

int dp[LEN];

int main()
{
    int N, M;
    cin >> N >> M;
    
    int arr[M + 2]; // M + 2: VIP 좌석 간의 일반 좌석 연산을 for문으로 연달아 처리하기 위함
    arr[0] = 0;
    arr[M + 1] = N + 1;
    for(int i = 0; i <  M; i++) {
        cin >> arr[i + 1];
    }
    
    dp[0] = 1; // VIP 좌석이 연달아 존재하는 경우
    dp[1] = 1; // VIP - 1 - VIP
    dp[2] = 2; // VIP - 1 - 2 - VIP
    for(int i = 3; i < LEN; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    
    int result = 1;
    int emptyChairNum = 0;
    
    for(int i = 0; i < M + 1; i++) {
        // VIP 좌석이 4, 7인 경우 두 좌석 사이의 일반좌석의 수는 7 - 4 - 1 = 2개 (5, 6)
        emptyChairNum = arr[i + 1] - arr[i] - 1;
        result *= dp[emptyChairNum];
    }

    cout << result;
    
    return 0;
}
