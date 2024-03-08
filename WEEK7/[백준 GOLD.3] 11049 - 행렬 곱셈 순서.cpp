// [백준 GOLD.3] 11049 - 행렬 곱셈 순서
// https://www.acmicpc.net/problem/11049

#include <iostream>
#include <vector>

using namespace std;

struct Mat {
    int r;
    int c;
};

int N;
Mat matrix[501];
int dp[501][501];

void dynamic() {
    for(int i = 1; i < N; i++) {
        for(int j = 1; i + j <= N; j++) {
            dp[j][i+j] = 1e9;
            for(int k = j; k <= i + j; k++) {
                dp[j][i+j] = min(dp[j][i+j], dp[j][k] + dp[k+1][i+j] + matrix[j].r * matrix[k].c * matrix[i+j].c);
            }
        }
    }
}

int main()
{
    cin >> N;
    
    int r, c;
    Mat temp;
    for(int i = 1; i <= N; i++) {
        cin >> temp.r >> temp.c;
        matrix[i] = temp;
    }
    
    dynamic();    
    cout << dp[1][N];   
}