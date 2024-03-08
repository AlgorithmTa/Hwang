// [백준 GOLD.3] 1644 - 소수의 연속합
// https://www.acmicpc.net/problem/1644

#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> primeV;
int counter = 0;


void eratosthenes() {
    
    bool isPrime[4000001];
    
    for(int i = 0; i <= N; i++) {
        isPrime[i] = true;
    }
    
    for(int i = 2; i * i <= N; i++) {
        for(int j = i + i; j <= N;) {
            isPrime[j] = false;
            j += i;
        }
    }
    
    for(int i = 2; i <= N; i ++) {
        if (isPrime[i] == true) {
            primeV.push_back(i);
        }
    }
}

void solve() {
    int startIdx = 0;
    int endIdx = 0;
    int currentVal = 0;
    
    while(true) {
        if (currentVal < N) {
            if (endIdx < primeV.size()) {
                currentVal += primeV[endIdx];
                endIdx += 1;
            } else {
                break;
            }
            
        } else if (currentVal > N) {
            currentVal -= primeV[startIdx];
            startIdx += 1;
        } else {
            counter += 1;
            if (endIdx < primeV.size()) {
                currentVal += primeV[endIdx];
                endIdx += 1;
            } else {
                break;
            }
        }
    }
}

int main()
{
    cin >> N;
    eratosthenes();
    solve();
    cout << counter;
}