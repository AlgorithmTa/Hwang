// [백준 PLATINUM.5] 20304 - 비밀번호 제작
// https://www.acmicpc.net/problem/20304

#include <iostream>
#include <queue>

#define MIN -1e9

using namespace std;

int N, M, p;
int arr[1000001] = { 0, };
queue<int> q;
int maxNum = 0;

int main() {
    cin >> N >> M;

    for(int i = 0; i <= N; i++) {
        arr[i] = MIN;
    }

    for(int i = 0; i < M; i++) {
        cin >>  p;
        q.push(p);

        // input으로 들어오는 값은 안전도가 0
        arr[p] = 0;
    }

    while(!q.empty()) {
        int current = q.front();
        q.pop();

        // 1 20개 > 100만
        for(int i = 0; i < 20; i++) {
            // current와 1을 i번 shift 연산한 이진수를 대상으로 XOR 연산
            // target = 현재 값과 XOR 연산에서 1만큼 차이나는 숫자
            // == target과 현재 값은 1만큼 차이난다 (가장 차이가 작은 경우)
            int target = current ^ (1 << i);

            // 범위값 N을 초과하거나 이미 해당 숫자가 갱신된 적이 있는 경우 continue
            if (target > N || arr[target] != MIN) {
                continue;
            }

            q.push(target);
            arr[target] = arr[current] + 1;
            maxNum = max(arr[target], maxNum);
        }
    }

    cout << maxNum;
}