// [백준 GOLD.4] 11404 - 플로이드
// https://www.acmicpc.net/problem/11404

#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    int a, b, c;
    int arr[n+1][n+1];
    
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            if (i == j) {
                arr[i][j] = 0;
            } else {
                arr[i][j] = 1000000000;
            }
        }
    }
    
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        arr[a][b] = min(arr[a][b], c);
    }
    
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if (arr[i][j] > arr[i][k] + arr[k][j]) {
                    arr[i][j] = arr[i][k] + arr[k][j];
                }
            }
        }
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if (arr[i][j] == 1000000000) {
                cout << 0 << ' ';
            } else {
                cout << arr[i][j] << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}