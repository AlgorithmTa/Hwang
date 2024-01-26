# [24.01.22~24.01.26 24:00] 3주차 스터디

|기간|24.01.22~24.01.26 24:00|
|:---:|:---|
|**링크**|[1. DNA 비밀번호](https://www.acmicpc.net/problem/12891)<br>[2. 우주 탐사선🔗](https://www.acmicpc.net/problem/17182)<br> [3. 빵집🔗](https://www.acmicpc.net/problem/3109) <br> [4. 감시 피하기🔗](https://www.acmicpc.net/problem/18428) <br> [5. 극장 좌석🔗](https://www.acmicpc.net/problem/2302)<br> [6. 피보나치 함수🔗](https://www.acmicpc.net/problem/1003)|


|문제 풀기 전 체감 난이도|빵집 > 우주 탐사선 > 감시 피하기 > 극장 좌석 > 피보나치 함수 > DNA 비밀번호|
|:---:|:---|
|문제 푼 후 난이도|우주 탐사선 > 빵집 > 극장 좌석 = 피보나치 함수 > 감시 피하기 > DNA 비밀번호|
- 🔥플로이드-워셜 DFS DP 문자열🔥

<details>
<summary><h4>DNA 비밀번호</h4></summary>

|풀이 예상 시간|실제 소요 시간|
|:---:|:---:|
|30m|50m|

<h4>풀이</h4>

- 문자열 + map(혹은 arr)

1. 전체 문자열에서 `P` 사이즈의 문자열을 처음부터 순차적으로 훑기
2. 시작지점 index를 `i`라고 가정했을 때, 이를 1씩 증가시키면 현재 문자열의 문자 갯수에서 제거되어야하는 character의 위치는 ⭐️`i - 1`⭐️, 추가되어야하는 character의 위치는 `i + P - 1`. 단, if문 내부에서 i의 index가 0이 아닌지 여러 번 if문을 연산하는 것은 비효율적이므로 for문은 1부터 시작한다.

```c++
    //  // 0번째 idx - (P-1)번째 idx가 조건을 만족하는지 판단하기 위함
    if (canMake()) {
        result += 1;
    }

    for(int i = 1; i <= lastIdx; i++) {
        char throwChar = s[i - 1];
        current[throwChar] -= 1;
            
        char addChar = s[i + P - 1];
        current[addChar] += 1;
        
        if (canMake()) {
            result += 1;
        }
    }
```

<h4>소감</h4>

- `substr`은 시간 초과의 직접적인 원인이 될 수 있다. 사용하지 않는 코드는 바로 지우자.

- 이번 코드에서는 `map<char, int>`로 데이터를 저장하지 않고 `int[]` 형태로 if문을 통한 문자열 비교 방식으로 풀어도 시간초과가 나지 않는다.
</details>

<details>
<summary><h4>우주 탐사선</h4></summary>

|풀이 예상 시간|실제 소요 시간|
|:---:|:---:|
|1h|1h50m|

<h4>풀이</h4>

- 플로이드-워셜

<3중 for문: 플로이드-워셜을 통한 모든 정점 to 모든 정점으로의 최단 경로 구하기>

```c++
for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (map[i][j] > map[i][k] + map[k][j]) {
                    map[i][j] = map[i][k] + map[k][j];
                }
            }
        }
    }
```
- 정점 i에서 정점 j까지로의 최단 경로 구하기
    -> `i -> j` 가 빠른가, `i -> k -> j` 가 빠른가

<dfs: 시작 지점으로부터 전체를 방문하기까지의 최단 경로 구하기>
1. `visited` bool 배열을 통한 방문 여부 확인
2. 전체 경우의 수 탐색 후 최소값 구하기

<h4>소감</h4>
- 호기롭게 Dijkstra로 시작했지만? 1시간동안 풀다가 for문을 전부 채울 수가 없어서 풀이를 보았더니 플로이드-워셜이었을 때의 심정을 서술하시오.
- `모든 정점에서 모든 정점으로의 최단 경로`는 플로이드-워셜을 사용하자

<h5>참고자료</h5>

[개념 공부🔗](https://m.blog.naver.com/PostView.nhn?blogId=ndb796&logNo=221234427842&proxyReferer=https:%2F%2Fwww.google.com%2F)

[Link🔗](https://imnotabear.tistory.com/233)
</details>

<details>
<summary><h4>빵집</h4></summary>

|풀이 예상 시간|실제 소요 시간|
|:---:|:---:|
|1h|40m|

<h4>풀이</h4>

- DFS

**어떻게 DFS로 풀 수 있는가?**

- 핵심은 row 탐색 순서를 오른쪽 상단(↗️)-오른쪽(➡️)-오른쪽 하단(↘️)의 순서대로 탐색하기
    
    -> 0번째 행으로부터 탐색을 하기 때문에, 오른쪽 하단이나 오른쪽을 먼저 탐색한다면 아래의 행에 있는 길이 막힐 가능성이 있으나, 위쪽 방향부터 차곡차곡 탐색한다면 아래 행의 길을 막지 않을 수 있음

|변수|설명|
|:---:|:---|
|bool visited[10001][501]|방문 여부 체크|
|int dr[3]|오른쪽 상단 - 오른쪽 - 오른쪽 하단 탐색을 위한 배열|
|isFindWay|각 행의 0번째 index에서부터 빵집까지 도달하는 가스관을 찾았는지에 대한 여부 판단|

`R`: 행 `C`: 열

1. for문을 통해 각각의 [R][0]의 위치를 기준으로 [R][C]에 도달 가능 여부를 판단하는 DFS 실행

    -> 단, isFindWay는 매번 false로 바꿔준다
2. DFS 내부에서 `dr` 배열의 값을 대상으로 오른쪽 -> 왼쪽 방향으로 탐색
    
    -> 단, 이미 1번의 `R`행에서 출발해서 빵집까지 도달하는 가스관을 찾았다면(`isFindWay == true`) 즉시 탈출


<h4>소감</h4>
- 왼쪽에서 오른쪽으로 가는 DFS

</details>

<details>
<summary><h4>감시 피하기</h4></summary>

|풀이 예상 시간|실제 소요 시간|
|:---:|:---:|
|1h|45m|

<h4>풀이</h4>

- 브루트포스

|변수|설명|
|:---:|:---|
|char map[6][6]| 전체 공간을 담을 2차원 배열|
|vector <Point> notTS|선생님과 학생이 아닌 빈 공간의 위치(`Point`) 담을 배열|
|vector<Point> teacherPosition|선생님의 위치를 담을 배열|

1. `pair<int. int>` first, second 대신 사용할 구조체 만들기

```c++
struct Point {
    int r;
    int c;
};
```

2. 입력으로 들어온 `map`에서 `notTS`, `teacherPosition`을 추출
3. `notTS`를 대상으로 장애물을 만들 위치를 3중 for문을 통해 고르기
4. 선생님의 위치로부터 상하좌우 방향으로 학생이 보이지 않는지 판별하기

<h4>소감</h4>
- 모든 문제를 어렵게 생각하지 말자

</details>

<details>
<summary><h4>극장 좌석</h4></summary>

|풀이 예상 시간|실제 소요 시간|
|:---:|:---:|
|30m|45m|

<h4>풀이</h4>

- DP

`int dp[41]에서 dp[i]의 의미`: 일반좌석이 i개 존재할 때 해당 좌석에 사람이 앉을 수 있는 경우의 수
```c++
    dp[0] = 1; // VIP 좌석이 연달아 존재하는 경우
    dp[1] = 1; // VIP - 1 - VIP
    dp[2] = 2; // VIP - 1 - 2 - VIP
    for(int i = 3; i < LEN; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
```

- 위의 식이 성립할 수 있는 이유는 일반좌석이 n개 있을 때 이 경우의 수가 n-1의 경우와 n-2의 경우를 더한 값과 동일하기 때문이다. (n >= 3)


**ex.**

    VIP - 1자리 - VIP: 1가지 (1)
    VIP - 2자리 - VIP: 2가지 (1-2) (2-1)
    VIP - 3자리 - VIP: 3가지 (1-2-3) (1-3-2) (2-1-3)
    VIP - 4자리 - VIP: 5가지 (1-2-3-4) (1-2-4-3) (1-3-2-4) (2-1-3-4) (2-1-4-3)

1. VIP좌석의 위치를 받을 배열 `arr`의 사이즈를 `M+2`로 선언
    
    -> VIP 좌석 간의 일반 좌석 연산을 for문으로 연달아 처리하기 위함
    
    -> 시작좌석 - VIP좌석, VIP좌석 - VIP좌석, VIP좌석 - 끝좌석
2. VIP 좌석 사이의 일반 좌석의 크기를 구한 후 미리 구했던 `int dp[41]`의 값을 `result`에 곱한다.


<h4>소감</h4>

- for문 범위값을 잘 확인하자
- `n` 과 `n + m` 사이에 존재하는 숫자의 갯수는 `m - 1`이다

</details>

<details>
<summary><h4>피보나치 함수</h4></summary>

|풀이 예상 시간|실제 소요 시간|
|:---:|:---:|
|15m|15m|

<h4>풀이</h4>

- DP

제한 시간 `0.25`초 & 피보나치
-> "아 이거 DP네"
1. fibonacci(0)의 경우에 사용되는 fibonacci(0), fibonacci(1)의 갯수 초기화
2. fibonacci(1)의 경우에 사용되는 fibonacci(0), fibonacci(1)의 갯수 초기화
3. 메모이제이션을 통해 DP zeroCount, oneCount pair 채워넣기

<h4>소감</h4>

- 이전 주차에서 어려운 DP문제를 풀어보기도 했고 알고 있던 개념(피보나치)이라 그런지 쉽게 풀었다.
</details>
