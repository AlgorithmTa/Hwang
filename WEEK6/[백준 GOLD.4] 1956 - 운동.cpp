// [백준 GOLD.4] 1956 - 운동
// https://www.acmicpc.net/problem/1956

#include <iostream>

using namespace std;

int V, E, K;


int main()
{
    cin >> V >> E;
    
    int dist[V+1];
    int arr[V+1][V+1];
    
    for(int i = 0; i <= V; i++) {
        for(int j = 0; j <= V; j++) {
            arr[i][j] = 100000000;
        }
    }
    
    int a, b, c;
    for(int i = 0; i < E; i++) {
        cin >> a >> b >> c;
        arr[a][b] = c;
    }
    

    for(int k = 1; k <= V; k++) {
        for(int i = 1; i <= V; i++) {
            for(int j = 1; j <= V; j++) {
                arr[i][j] = min(arr[i][k] + arr[k][j], arr[i][j]);
            }
        }
    }
    
    int result = 100000000;
    for(int i = 1; i <= V; i++) {
        result = min(result, arr[i][i]);
    }
    
    if (result == 100000000) {
        cout << -1;
    } else {
        cout << result;
    }
}