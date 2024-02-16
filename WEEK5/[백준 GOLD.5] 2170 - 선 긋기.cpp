// [백준 GOLD.5] 2170 - 선 긋기
// https://www.acmicpc.net/problem/2170

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    vector<pair<long, long>> v;
    int N;

    cin >> N;
    int s, e;
    for(int i =0; i < N; i++) {
        cin >> s >> e;
        v.push_back({s, e});
    }

    sort(v.begin(), v.end());

    long long counter = 0;
    s = 0;
    e = 0;

    long long tempS, tempE;
    for(int i = 0; i < v.size(); i++) {
        tempS = v[i].first;
        tempE = v[i].second;

        if (e < tempS) {
            counter += e - s;
            s = tempS;
            e = tempE;
        }

        if (s > tempS) {
            s = tempS;
        }
        if (e < tempE) {
            e = tempE;
        }
    }
    counter += e - s;
    cout << counter;
}