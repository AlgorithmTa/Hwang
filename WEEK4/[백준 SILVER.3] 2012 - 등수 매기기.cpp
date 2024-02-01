// [백준 SILVER.3] 2012 - 등수 매기기
// https://www.acmicpc.net/problem/2012

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    vector<int> v;
    cin >> N;
    
    int num;
    for(int i = 0; i < N; i++) {
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    
    long long result = 0;
    for(int i = 0; i < N; i++) {
        result += abs(v[i]-(i+1));
    }

    cout << result;
    return 0;
}