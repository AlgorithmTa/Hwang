# [24.03.04~24.03.08 24:00] 7주차 스터디

|기간|24.03.04~24.03.08 24:00|
|:---:|:---|
|**링크**|[1. 최소 스패닝 트리🔗](https://www.acmicpc.net/problem/1197)<br>[2. ACM Craft🔗](https://www.acmicpc.net/problem/1005)<br> [3. 소수의 연속합🔗](https://www.acmicpc.net/problem/1644) <br> [4. LCS 2🔗](https://www.acmicpc.net/problem/9252) <br> [5. 행렬 곱셈 순서🔗](https://www.acmicpc.net/problem/11049)<br>|


|문제 풀기 전 체감 난이도|LCS 2 > 행렬 곱셈 순서 >>> ACM Craft > 최소 스패닝 트리 > 소수의 연속합|
|:---:|:---|
|문제 푼 후 난이도|행렬 곱셈 순서 > LCS 2 >>> ACM Craft > 최소 스패닝 트리 > 소수의 연속합|
- 🔥Dynamic-Programming LCS 투포인터🔥

<details>
<summary><h4>최소 스패닝 트리</h4></summary>

|풀이 예상 시간|실제 소요 시간|
|:---:|:---:|
|40m|40m|

<h4>풀이</h4>

- 최소 신장 트리...? 왜 이렇게 Dijkstra 같은지...
- ... Dijkstra이지 않나? (근데 이제 음의 간선이 있는...)

1. 간선 정보를 이차원 벡터에 넣는다
2. 첫번째 정점을 기준으로 BFS탐색과 함께 노드 방문 여부를 체크한다.

    -> 노드를 방문하지 않은 경우, 해당 간선의 가중치를 더한다.

<h4>소감</h4>

- 또 모르는 개념...
- 이번에는 프림 알고리즘으로 풀었지만 다음에는 프루스칼로 풀어보자

</details>

<details>
<summary><h4>ACM Craft</h4></summary>

|풀이 예상 시간|실제 소요 시간|
|:---:|:---:|
|??m|40m|

<h4>풀이</h4>

- 위상 정렬과 DP

1. 입력받은 정보들에 대하여 `Y`(X->Y)로 향하는 길이 몇 개가 있는지 저장하는 `howManyRoadsTo`에 정보를 저장한다.
2. queue에 `howManyRoadsTo`가 0인 정보에 한하여 저장한다.
    -> 이와 함께 i번째 노드로 향하는 데 걸리는 시간을 이전에 input으로 받았던 값으로 갱신한다.
3. 큐가 빌 때까지 현재 노드에서 다음 노드로 향할 때, `다음노드까지 걸리는 시간`을 최대값으로 갱신한다.
    -> + 다음 노드로 향하는 길의 탐색이 이미 종료되었다면, 큐에 넣기

<h4>소감</h4>

- 또... 새로운 개념
- 세상은 넓고 새로운 문제는 많다... 특정 노드로 향하는 경로의 수를 세는 문제는 처음이네

<h5>참고자료</h5>

[Link🔗](https://scarlettb.tistory.com/123)

</details>

<details>
<summary><h4>소수의 연속합</h4></summary>

|풀이 예상 시간|실제 소요 시간|
|:---:|:---:|
|40m|50m|

<h4>풀이</h4>

- 에라토스테네스의 체 + 투 포인터

1. `에라토스테네스의 체` 로직으로 4000000까지의 수 중에서 소수를 찾아 `primeV`에 저장
2. 투 포인터를 통해 현재 `primeV`에서 연속합이 N인 수가 있는지 찾는다.
    -> 단 초기 설정값이 startIdx = endIdx이므로 while문 break포인트는 if문 내부에 걸어준다

<h4>소감</h4>

- 오랜만에 푼 에라토스테네스

</details>

<details>
<summary><h4>LCS 2</h4></summary>

|풀이 예상 시간|실제 소요 시간|
|:---:|:---:|
|??m|45m|

<h4>풀이</h4>

- LCS

1. 두 String의 문자가 동일한지 비교하며 이차원배열에 현재까지 몇 개의 수가 중복되었는지 체크한다.
    
    -> 동일하지 않은 경우, 이전의 각 (행-1,열), (행, 열-1) 요소 중에서 큰 값을 넣는다.

2. 구성이 완료된 이차원 배열에서 LCS 문자열을 찾는다
    -> 각 열의 요소가 동일한 경우에는 탐색 범위를 열의 탐색 범위를 줄인다
    -> 각 행의 요소가 동일한 경우에는 계속해서 탐색한다.
    -> 이외의 경우에는 `resultS`의 앞에 문자를 붙인다.

<h4>소감</h4>

- 처음 풀어보는 유형의 문제라고 생각해서 개념 학습하고 구글링하면서 풂...
- 아직 익숙하지 않아서 반복적인 학습이 필요해보임

<h5>참고자료</h5>

[개념 공부🔗](https://velog.io/@emplam27/알고리즘-그림으로-알아보는-LCS-알고리즘-Longest-Common-Substring와-Longest-Common-Subsequence)

[Link🔗](https://velog.io/@zeesouth/알고리즘-최장-공통-부분-수열-LCS-Longest-Common-Subsequence)

[Link🔗](https://hyeo-noo.tistory.com/18)
</details>

</details>

<details>
<summary><h4>행렬 곱셈 순서</h4></summary>

|풀이 예상 시간|실제 소요 시간|
|:---:|:---:|
|??m|50m|

<h4>풀이</h4>

- Dynamic Programming

|dp[n][m]|n번째 matrix부터 m번째 matrix까지의 행렬 연산의 결과 중 가장 작은 값으로 갱신|
|:---:|:---|

1. **for 1**: i만큼의 간격을 지니는 n-m번째 매트릭스들에 대하여

    ex. i == 1 : d[1][2], d[2][3]

2. **for 2**: N까지의 범위 내에서

    ex. i == 1, N == 5 : d[1][2], d[2][3] ... d[4][5]

3. **for 3**: k로 나눈 i to i+j 구간의 N * M * K 최소값을 구한다

```c++
void dynamic() {
    for(int i = 1; i < N; i++) { // for 1
        for(int j = 1; i + j <= N; j++) { // for 2
            dp[j][i+j] = 1e9;
            for(int k = j; k <= i + j; k++) { // for 3
                dp[j][i+j] = min(dp[j][i+j], dp[j][k] + dp[k+1][i+j] + matrix[j].r * matrix[k].c * matrix[i+j].c);
            }
        }
    }
}
```

<h4>소감</h4>

- 시간 제한이랑 문제 조건 보고 DP라고 예상했으나 점화식을 도출하지 못한 비운의 문제

<h5>참고자료</h5>

[Link🔗](https://cocoon1787.tistory.com/318)
</details>

</details>