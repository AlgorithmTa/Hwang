# [24.02.19~24.03.01 24:00] 6주차 스터디

|기간|24.02.19~24.03.01 24:00|
|:---:|:---|
|**링크**|[1. 스카이라인🔗](https://www.acmicpc.net/problem/1933)<br>[2. 최단경로🔗](https://www.acmicpc.net/problem/1753)<br> [3. 특정 거리의 도시 찾기🔗](https://www.acmicpc.net/problem/18352) <br> [4. 운동🔗](https://www.acmicpc.net/problem/1956) <br> [5. 전깃줄🔗](https://www.acmicpc.net/problem/2565)<br> [6. 연속부분최대곱🔗](https://www.acmicpc.net/problem/2670)<br> [7. 회사 문화 1🔗](https://www.acmicpc.net/problem/14267)<br> [8. 회전 초밥🔗](https://www.acmicpc.net/problem/15961)|


|문제 풀기 전 체감 난이도|스카이라인 > 운동 > 최단경로 > 특정 거리의 도시 찾기 > 회전초밥 > 전깃줄 > 연속부분최대곱 = 회사 문화 1|
|:---:|:---|
|문제 푼 후 난이도|스카이라인 > 운동 > 최단경로 > 회전초밥 > 전깃줄 > 특정 거리의 도시 찾기 > 연속부분최대곱 = 회사 문화 1|
- 🔥MultiSet 플로이드-워셜 Dijkstra 슬라이딩-윈도우 DP DFS🔥

<details>
<summary><h4>스카이라인</h4></summary>

|풀이 예상 시간|실제 소요 시간|
|:---:|:---:|
|??m|??m|

<h4>풀이</h4>

- MultiSet
- 충분한 이해 후 풀이와 함께 코드를 올릴 예정

<h4>소감</h4>

- 
</details>

<details>
<summary><h4>최단경로</h4></summary>

|풀이 예상 시간|실제 소요 시간|
|:---:|:---:|
|40m|25m|

<h4>풀이</h4>

- Dijkstra

1. 이차원 벡터에 각 간선의 정보를 담는다
    
    -> 단, pair에서 순서는 pair<거리, 목적지>로 priority_queue에서 사용될 pair의 순서와 일치시키자
2. 시작 도시 K를 기준으로 priority_queue를 통해 Dijkstra를 수행한다.

    -> 단, priority_queue에 도시 정보를 추가하는 것은 최소 값이 갱신되었을 경우에 한하여 저장한다.
3. 특정 도시로의 최단 거리를 저장한 dist 배열의 값을 순차적으로 출력한다

    -> 단, dist의 값이 초기값(100000000)인 경우, INF를 출력한다.

<h4>소감</h4>

- 간선을 넣는 pair<int, int>와 priority_queue에서 사용하는 pair<int, int>의 자료 순서는 통일시키자
</details>

<details>
<summary><h4>특정 거리의 도시 찾기</h4></summary>

|풀이 예상 시간|실제 소요 시간|
|:---:|:---:|
|40m|30m|

<h4>풀이</h4>

- Dijkstra

1. 이차원 vector에 각 단방향 도로의 시작 위치와 끝 위치를 담는다
2. 시작 도시 X를 기준으로 하여 priority_queue를 통해 Dijkstra를 수행한다.
    
    -> 단, priority_queue에 도시 정보를 추가하는 것은 최소 값이 갱신되었을 경우에 한하여 저장한다.
3. 특정 도시로의 거리가 K인 경우 출력하고 counter를 1 증가시킨다.

    -> for문 내부에서 만족하는 값이 없어 counter가 0이라면 -1을 출력한다.

<h4>소감</h4>

- 간단한 Dijkstra...
- 이제 풀이를 보지 않고 풀 수 있는 Dijkstra 문제가 생겼다 🥹
</details>

<details>
<summary><h4>운동</h4></summary>

|풀이 예상 시간|실제 소요 시간|
|:---:|:---:|
|40m|40m|

<h4>풀이</h4>

- 플로이드-워셜

1. input으로 받은 a to b까지의 c 거리를 이차원 배열(arr)에 넣는다
2. arr을 대상으로 플로이드-워셜을 수행한다.
3. i 지점에서 다시 i 지점으로 돌아오는, 즉 arr[i][i]에 담긴 값을 비교하며 최소값(result)을 찾아 출력한다.
    
    -> 단, 해당 for문이 끝난 후에도 여전히 result의 값이 초기값(100000000)이라면 -1을 출력한다.
<h4>소감</h4>

- 플로이드-워셜이 쓰인다고 힌트를 보기 전 까지는 Dijkstra라고 생각했떤 문제. 시작 지점으로 돌아온다는 조건, 범위값이 넓지 않다면 플로이드-워셜을 빠르게 생각해보자.

</details>

<details>
<summary><h4>전깃줄</h4></summary>

|풀이 예상 시간|실제 소요 시간|
|:---:|:---:|
|35m|30m|

<h4>풀이</h4>

- DP

1. pair로 전깃줄의 값을 받아 벡터에 저장 후 정렬한다.
2. 특정 선의 기준으로 교차되는 전깃줄이 있는지 판별한다
    
    -> 여기서 교차되기 위한 조건은 B의 값이 기준이 되는 i의 B보다 비교되는 j의 B가 작은 경우

<h4>소감</h4>

- 전역변수로 배열 선언 시 자동으로 0으로 초기화되지만, 지역변수의 경우에는 그렇지 않음에 주의하자
</details>

<details>
<summary><h4>연속부분최대곱</h4></summary>

|풀이 예상 시간|실제 소요 시간|
|:---:|:---:|
|30m|20m|

<h4>풀이</h4>

- DP

|DP[i]|i번째 숫자에서 연속되는 수열 중 가장 큰 값|
1. input으로 받는 숫자(num)에 대하여, 이전까지의 결과를 담는 것이 클지, num 그대로 담는 것이 클지 판별한다.
2. DP배열의 최대값을 찾는다
3. 소숫점 아래 3자리까지만 남을 수 있도록 precision

<h4>소감</h4>

- 간단한 DP!

</details>

<details>
<summary><h4>회사 문화 1</h4></summary>

|풀이 예상 시간|실제 소요 시간|
|:---:|:---:|
|30m|30m|

<h4>풀이</h4>

- DFS

1. 이차원 벡터를 통해 직속 상사와 부하를 매칭한다
2. 각 사원이 받은 칭찬 수치를 compliments vector에 저장
3. 각 직속 상사의 부하 직원들에 대해 DFS를 수행하며 compliments 값을 증가시킨다.

```c++
void DFS(int current) {
    for(int i = 0; i< v[current].size(); i++) {
        int next = v[current][i];
        compliments[next] += compliments[current];
        DFS(next);
    }
}
```

<h4>소감</h4>

- 간단한 DFS

</details>

<details>
<summary><h4>회전 초밥</h4></summary>

|풀이 예상 시간|실제 소요 시간|
|:---:|:---:|
|30m|50m|

<h4>풀이</h4>

- 투 포인터 & 슬라이딩 윈도우

1. input으로 받은 값을 k 사이즈의 윈도우를 한 칸씩 이동하며 최대로 먹을 수 있는 초밥의 가짓수를 갱신한다.
    
    -> 단, 윈도우 내부에 무료 초밥이 존재하는 경우와 존재하지 않는 경우를 고려한다.
```c++
    if (m.find(c) == m.end()) {
        result = max(result, mSize + 1);
    } else {
        result = max(result, mSize);
    }
```

<h4>소감</h4>

- unordered_map 대신 map을 사용하면 시간초과가 난다.
- unordered_map은 해시 테이블을 사용하여 데이터를 저장해서 검색, 삽입 및 삭제 연산이 일반적으로 O(1)의 시간 복잡도를 가지지만, map은 레드-블랙 트리를 사용해서 데이터를 저장하기 때문에 이러한 연산에 O(log n)의 시간 복잡도를 가진다.

<h5>참고자료</h5>

[Link🔗](https://bbeomgeun.tistory.com/122)

</details>