# [24.01.13~24.01.19 24:00] 2주차 스터디

|기간|24.01.13~24.01.19 24:00|
|:---:|:---|
|1주차 연습문제|[석유 시추](https://school.programmers.co.kr/learn/courses/30/lessons/250136)|
|**링크**|[1. 두 큐 합 같게 만들기🔗](https://school.programmers.co.kr/learn/courses/30/lessons/118667) <br> [2. 성격 유형 검사하기🔗](https://school.programmers.co.kr/learn/courses/30/lessons/118666) <br> [3. 등산코스 정하기🔗](https://school.programmers.co.kr/learn/courses/30/lessons/118669) <br> [4. 코딩 테스트 공부🔗](https://school.programmers.co.kr/learn/courses/30/lessons/118668)<br> [5. 행렬과 연산🔗](https://school.programmers.co.kr/learn/courses/30/lessons/118670)|


|문제 풀기 전 체감 난이도|등산코스 정하기 > 코딩 테스트 공부 > 석유 시추 > 두 큐 합 같게 만들기 > 행렬과 연산 > 성격 유형 검사하기|
|:---:|:---|
|문제 푼 후 난이도|등산코스 정하기 > 석유 시추 > 코딩 테스트 공부 > 행렬과 연산 > 두 큐 합 같게 만들기 > 성격 유형 검사하기|
- 🔥Dijkstra BFS DP PQ DEQUE TwoPointer🔥

<details>
<summary><h4>석유 시추</h4></summary>
<h4>풀이</h4>

- BFS + Map, Set etc 다양한 자료구조

<for문: BFS 수행부>

1. 방문하지 않고 석유가 있는 영역이라면 해당 위치(r, c)에서 BFS를 수행한다.

    <BFS 수행>
    1. (r, c)에서 상하좌우 영역에 석유가 있는지 탐색하기 위한 시작 위치를 queue에 담는다.
    2. 탐색할 때마다 석유 존재 영역(`oilAreaSize`)을 1씩 더한다.
    2. 범위를 초과하거나, 이미 방문했거나, 석유가 없는 지점일 경우 `continue`
    3. `2`의 경우가 아니라면 탐색한 위치에 `depth`번째 oilArea임을 표시한다.
    4. 큐에서 더 이상 상하좌우로 탐색할 수 있는 영역이 없다면, `depth`번째 oilArea의 사이즈를 `oilAreaSize`로 확정한다.
<for문: 석유 시추량 최대값 구하기 수행부>
1. 각각의 열에 시추 파이프를 내릴 것이기 때문에 열 -> 행의 순으로 for문 수행
2. 해당 열에서 접근 가능한 시추 영역의 전체 사이즈 추출
3. `answer`에 담아둔 값을 1,2에서 수행한 결과오 비교하며 최대값을 갱신한다.

<h4>소감</h4>

- 매개변수로 큰 사이즈의 자료를 넘기는 것도 시간 초과의 요인이 될 수 있다. 사용하지 않거나 혹은 함수 호출 시에 지속적으로 사용해야만하는 변수는 전역으로 선언해두자

</details>

<details>
<summary><h4>두 큐 합 같게 만들기</h4></summary>

|풀이 예상 시간|실제 소요 시간|
|:---:|:---:|
|1h|1h30m|

<h4>풀이</h4>

- 투 포인터

1. 각 queue에 들어있는 요소를 더한다.

<while문: 두 큐의 합을 같게 만들 수 있는지 판별>
1. 각 요소의 이동이 queue1과 queue2의 전체 사이즈를 왕복했을 때에도 답이 나오지 않는다면 `-1(불가능)`로 종료

|변수|설명|
|:---:|:---|
|s1|`queue1` 시작 지점|
|e1|`queue1` 끝 지점|
|s2|`queue2` 시작 지점|
|e2|`queue2` 끝 지점|

|경우|방법|
|:---:|:---|
|경우 1. `queue1Sum` < `queue2Sum`|`queue2Sum`에서 `s2` 값 제거<br>`s2` 위치 증가<br>`e1` 위치 증가<br>`queue1Sum`에 `e1` 값 추가|
|경우 2. `queue1Sum` > `queue2Sum`|`queue1Sum`에서 `s1` 값 제거<br>`s1` 위치 증가<br>`e2` 위치 증가<br>`queue2Sum`에 `e2` 값 추가|
|경우 3 `queue1Sum` = `queue 2Sum`| `return answer`|



<h4>소감</h4>

- 매개변수 이름이 queue이지만 실제 타입은 vector일 수 있다는 점에 유의하자
- `answer`의 기본 설정 값이 0이 아니라 -2일 수 있다는 점에 유의하자
- 전위연산 및 후위연산이 함께 사용되는 경우를 잘 판단하자

<h5>참고자료</h5>

[Link🔗](https://cherishvert.tistory.com/111)

</details>

<details>
<summary><h4>성격 유형 검사하기</h4></summary>
<h4>풀이</h4>
- string + map

<for문: 각 성격 요소별 점수 계산>
1. `survey`로 들어온 string 값을  미리 만들어둔 스코어보드 `scoreX`를 사용해 성격 유형별 map에 매칭해서 점수를 더한다.

<if문: 성격 유형별 score 비교>
1. 각각의 성격 유형별로 score를 비교하여 answer에 해당 유형을 더한다.

<h4>소감</h4>

- ⭐️ **index에 주의하자. index에 주의하자. index에 주의하자** ⭐️
</details>

<details>
<summary><h4>등산코스 정하기</h4></summary>

|풀이 예상 시간|실제 소요 시간|
|:---:|:---:|
|1h|2h30m|

<h4>풀이</h4>

- Dijkstra

각각의 노드에서 뻗어나가는 줄기의 최소값 구하기
1. node를 연결한다 (구조는 node : node : 두 node 사이의 거리)
2. priorityQueue를 사용해 두 node 사이의 값이 작은 순서대로 정렬하며, 출입구들을 넣는다

<while문: 각각의 노드에 대한 dist값 판별>
1. 해당 while문은 `pq`가 빌 때까지 수행한다. (dijkstra의 수행이 끝나 각 node 간의 최소 intensity를 구하기까지 수행)
2. `pq`의 top에 위치한 node(`currentNode`)와 `currentNode`와 연결되어 있는 인접 노드(`nextNode`)의 dist값을 비교하여 dist값을 갱신한다.
3. 산봉우리가 아닌 경우, `nextNode`를 `pq`에 추가한다. (산봉우리를 두 번 이상 방문하는 일을 만들지 않기 위함)


<h4>소감</h4>

- Dijkstra 개념 여러 번 복습하자!

<h5>참고자료</h5>

[개념 공부🔗](https://blog.encrypted.gg/1037)

[Link🔗](https://howudong.tistory.com/334)

[Link🔗](https://github.com/encrypted-def/kakao-blind-recruitment/blob/master/2022-summer-internship/Q4.cpp)
</details>

<details>
<summary><h4>코딩 테스트 공부</h4></summary>

|풀이 예상 시간|실제 소요 시간|
|:---:|:---:|
|1h|1h10m|

<h4>풀이</h4>

- Dynamic Programming

1. 문제 풀이에 필요한 알고력과 코딩력 max값 구하기
    - 단 사용자의 default alp와 cop가 max보다 큰 경우 두 값 중 작은 값으로 고정하기 (이미 모든 문제 풀이가 가능한 조건 도달 지점에 해당)
2. DP 수행 Array 초기화
    - dp[alp][cop]를 제외한 모든 지점을 MAX값으로 설정

<DP: 목표 알고력 코딩력데 도달하기 위한 최단 시간 구하기 수행부>

<---: default 알고력(alp) & 코딩력(cop)부터 시작하는 이중 for문>

1. alp와 cop를 1시간 공부를 통해 올리는 경우, 해당 dp 배열의 값을 min값으로 갱신    
        
    ```c++
    dp[i+1][j] = min(dp[i+1][j], dp[i][j] + 1);
    dp[i][j+1] = min(dp[i][j+1], dp[i][j] + 1);
    ```
        
2. alp와 cop를 문제 풀이를 통해 올리는 경우, 해당 dp 배열의 값을 min값으로 갱신
    - 단, 현재 `i` `j` 의 값이 문제를 풀 수 있는 값에 도달해야함
    - 단 max값 도달 자체가 "모든 문제들을 풀 수 있는" 조건을 만족시키므로 알고력과 코딩력의 max값과 현재 `i` `j`에 `reward`를 더한 값 간의 비교가 필요함
        
    ```c++
    int target_alp = min(alp_max, i + alp_rwd);
    int target_cop = min(cop_max, j + cop_rwd);
    dp[target_alp][target_cop] = min(dp[target_alp][target_cop], dp[i][j] + cost);
    ``````    

<h4>소감</h4>

- DP는 언제봐도 점화식을 유도하기가 쉽지 않은 것 같다. 여러 문제를 접하면서 알아갈 수 밖에 없는듯!

<h5>참고자료</h5>

[카카오 문제 해설🔗](https://tech.kakao.com/2022/07/13/2022-coding-test-summer-internship/)

[Link🔗](https://blog.encrypted.gg/1077)

[Link🔗](https://velog.io/@0_hun/프로그래머스-코딩-테스트-공부-2022-KAKAO-TECH-INTERNSHIP-Level-3-Python)
</details>

<details>
<summary><h4>행렬과 연산</h4></summary>

|풀이 예상 시간|실제 소요 시간|
|:---:|:---:|
|1h|1h20m|

<h4>풀이</h4>

- Deque

해설 없이 고민할 땐 `operations` 배열에서 같은 연산이 연속적으로 나오면(`ShiftRow - ShiftRow -Shift...`) 이걸 모아서 처리하는 방법을 생각했으나, 연속적이지 않고 `ShiftRow - Rotation - ShiftRow - Rotation...`과 같은 경우에는 결국 시간 초과가 날 것 같았음

<Conditon: 이차원 vector 분할>
1. `좌측 열(col_left) - 중앙부 열(rows) - 우측 열(col_right)`로 분리

<ShiftRow: 행 옮기기>
1. `col_left`와 `col_right`의 back을 front에 붙이기
2. `rows` 행렬 전체를 바꾸지 않고, 첫 행의 시작 인덱스(`startRowIndex`)만 변경하기

<Rotation: 회전하기>
1. 시계방향으로 각 deque의 front(back)을 알맞은 위치에 붙이기
(startRowIndex와 관련된 사칙연산에 주의하기!)

<Print: 결과 출력>
1. `col-left`의 front - `rows`의 요소 - `col-right`의 front 순으로 출력하기

<h4>소감</h4>

- [백준 AC](https://www.acmicpc.net/problem/5430)나 [큐빙](https://www.acmicpc.net/problem/5373)이 생각나는 문제
- deque 개념만 알고 있으면 생각보다 쉽게 풀 수 있는 문제. 왜 직접 풀 때는 이런 자료구조나 이 알고리즘을 써야겠다! 하고 생각이 안날까...

<h5>참고자료</h5>

[카카오 문제 해설🔗](https://tech.kakao.com/2022/07/13/2022-coding-test-summer-internship/)

[Link🔗](https://blog.encrypted.gg/1079)

</details>
