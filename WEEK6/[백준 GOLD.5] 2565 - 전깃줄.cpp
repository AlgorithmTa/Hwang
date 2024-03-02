// [백준 GOLD.5] 2565 - 전깃줄
// https://www.acmicpc.net/problem/2565

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<int, int>> v;
int DP[101];

int main()
{
    cin >> N;
    int a, b;
    for(int i = 0; i < N; i++) {
        cin >> a >> b;
        v.push_back({a, b});
    }
    
    
    sort(v.begin(), v.end());
    
    int result = 500;
    for(int i = 1; i < N; i++) {
        for(int j = i - 1; j >= 0; j--) {
            if (v[i].second > v[j].second) {
                if (DP[i] <= DP[j]) {
                    DP[i] = DP[j] + 1;
                }
            }
            result = min(result, N - DP[i] - 1);
        }
    }
    
    cout << result;
}