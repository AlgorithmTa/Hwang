// [백준 GOLD.4] 9663 - N-Queen
// https://www.acmicpc.net/problem/9663

#include <iostream>

using namespace std;

int N;
int arr[16];
int counter = 0;

bool isPossible(int current) {
    for(int i = 0; i < current; i++) {
        if (arr[i] == arr[current] || abs(arr[i] - arr[current]) == abs(i - current)) {
            return false;
        }
    }
    
    return true;
}

void backTracking(int current) {
    if (current == N) {
        counter += 1;
        return;
    } else {
        for(int i = 0; i < N; i++) {
            arr[current] = i;
            if(isPossible(current)) {
                backTracking(current + 1);
            }
        }
    }
}

int main() {
    cin >> N;
    backTracking(0);

    cout << counter;
}
