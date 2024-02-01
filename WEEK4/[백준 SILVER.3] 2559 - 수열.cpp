// [백준 SILVER.3] 2559 - 수열
// https://www.acmicpc.net/problem/2559

#include <iostream>

using namespace std;

int arr[100001] = { 0, };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N, K;
    cin >> N >> K;
    
    int currentMax = 0;
    for(int i = 0; i < K; i++) {
        cin >> arr[i];
        currentMax += arr[i];
    }
    
    int throwNumIdx = 0;
    int temp = currentMax;
    for(int i = K; i < N; i++) {
        cin >> arr[i];
        temp = temp - arr[throwNumIdx] + arr[i];
        currentMax = max(temp, currentMax);
        throwNumIdx += 1;
    }
    
    cout << currentMax;
    return 0;
}