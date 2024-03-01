// [백준 SILVER.4].2670 - 연속부분최대곱
// https://www.acmicpc.net/problem/2670

#include <iostream>
#include <cmath>

using namespace std;

double DP[10001] = { 0, };
int main()
{
    int N;
    cin >> N;
    
    double num;
    DP[0] = 1;
    for(int i  = 1; i <= N; i++) {
        cin >> num;
        DP[i] = max(DP[i-1] * num, num);
    }
    
    double maxVal = 0;
    for(int i = 1; i <= N; i++) {
        maxVal = max(maxVal, DP[i]);
    }
    
    cout << fixed;
    cout.precision(3);
    cout << maxVal;
    return 0;
}
