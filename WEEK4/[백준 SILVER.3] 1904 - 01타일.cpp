// [백준 SILVER.3] 1904 - 01타일
// https://www.acmicpc.net/problem/1904

#include <iostream>

using namespace std;

long long DP[1000001];

void fibonacci() {
    for(int i = 3; i <= 1000000; i++) {
        DP[i] = (DP[i-1] + DP[i-2]) % 15746;
    }
}

int main()
{
    int N;
    cin >> N;
    
    DP[1] = 1;
    DP[2] = 2;
    
    fibonacci();
    
    cout << DP[N];
    return 0;
}