# [24.02.04~24.02.16 24:00] 4주차 스터디

|기간|24.02.04~24.02.16 24:00|
|:---:|:---|
|4주차 연습문제|[단어 뒤집기 2](https://www.acmicpc.net/problem/17413)<br>[RGB거리](https://www.acmicpc.net/problem/1149)|
|링크|[1. 플로이드🔗](https://www.acmicpc.net/problem/11404)<br>[2. n단 논법🔗](https://www.acmicpc.net/problem/15723)<br>[3. 요세푸스 문제🔗](https://www.acmicpc.net/problem/1976)<br>[4. 여행가자🔗](https://www.acmicpc.net/problem/2665)<br>[5. N-Queen🔗](https://www.acmicpc.net/problem/9663)<br>[6. 최소비용 구하기🔗](https://www.acmicpc.net/problem/1916)<br>[7. 제곱수의 합🔗](https://www.acmicpc.net/problem/1699)<br>[8. 비밀번호 제작🔗](https://www.acmicpc.net/problem/20304)<br>[9. 선 긋기🔗](https://www.acmicpc.net/problem/2170)<br>[10. 트리와 쿼리🔗](https://www.acmicpc.net/problem/15681)<br>|

|문제 풀기 전 체감 난이도| 비밀번호 제작 > 제곱수의 합 > 여행 가자 > N-Queen > 트리와 쿼리 > 최소비용 구하기 > 선 긋기 > RGB거리 > 플로이드 = n단 논법 > 요세푸스 문제 > 단어 뒤집기 2|
|:---:|:---|
|문제 푼 후 난이도| 비밀번호 제작 > 제곱수의 합 > 최소비용 구하기 > N-Queen > 여행 가자 > RGB거리 > 선 긋기 > 트리와 쿼리 = 단어 뒤집기 2 > 플로이드 = n단 논법 > 요세푸스 문제|
- 🔥비트마스킹 BFS Dynamic-Programming Union-Find Back-Tracking Dijkstra 라인-스위핑 트리 플로이드-워셜🔥

<details>
<summary><h4>단어 뒤집기 2</h4></summary>

|풀이 예상 시간|실제 소요 시간|
|:---:|:---:|
|20m|35m|

<h4>풀이</h4>

- stack with char


    <for문: 단어 뒤집기 및 출력 여부 판단>
    
    1. 공백(' ')을 만난 경우
        a. 괄호 내부 O: stack에 push
        b. 괄호 내부 X: stack에 담긴 char 전체 출력
    2. 공백(' ')이 아닌 경우
        a. 여는 괄호('<'): 괄호 시작 bool을 `true`로 전환 후 stack에 담긴 char 전체 출력
        --- stack에 push ---
        b. 닫는 괄호('>'): stack에 담긴 char를 `reverse` 후 출력 및 괄호 시작 bool을 `false`로 전환

    **주요 포인트**
    
    - stack은 LIFO이므로 abcd 를 stack에서 pop하면 bcda로 나옴
    
        -> `reverse`의 의미는 abcd를 abcd 그대로 출력하겠다의 의미가 됨
    - 공백(' ')이 아닌 경우 stack에 해당 char를 push하는 연산이 중앙에 위치한 이유는 여는 괄호일 경우, 이를 포함시키지 않고 출력해야하기 때문이다

<h4>소감</h4>

- stack은 LIFO, queue는 FIFO

</details>

<details>
<summary><h4>RGB거리</h4></summary>

|풀이 예상 시간|실제 소요 시간|
|:---:|:---:|
|45m|30m|

<h4>풀이</h4>

- Dynamic Programming

- DP[N][3]: r, g, b 각각을 저장하는 3사이즈의 N개 배열

1. input으로 r, g, b 거리를 받는다
2. Dynamic Programming을 통해 r, g, b 중 어떤 색상을 칠하는게 비용이 적을 수 있는지 판단한다

    -> 단, 이전 칸의 색상과 현재 칸의 색상이 중복되면 안된다는 점에 유의하자.
    
    DP[i][0]: i번째 칸에서 빨강을 택한 경우
    
    DP[i][1]: i번째 칸에서 초록을 택한 경우
    
    DP[i][2]: i번째 칸에서 파랑을 택한 경우

    |점화식|설명|
    |:---:|:---|
    |DP[i][0] = min(DP[i-1][1] + DP[i][0], DP[i-1][2] + DP[i][0])<br>DP[i][1] = min(DP[i-1][0] + DP[i][1], DP[i-1][2] + DP[i][1])<br>DP[i][2] = min(DP[i-1][0] + DP[i][2], DP[i-1][1] + DP[i][2])|i번째 칸에서 특정 색상을 칠한 경우, 이전 칸의 색상과 중복되지 않는 색상을 칠한 경우의 결과를 더한 최소값으로 갱신한다.|
    
```c++
    for(int i = 1; i < N; i++) { 
        DP[i][0] = min(DP[i-1][1] + DP[i][0], DP[i-1][2] + DP[i][0]);
        DP[i][1] = min(DP[i-1][0] + DP[i][1], DP[i-1][2] + DP[i][1]);
        DP[i][2] = min(DP[i-1][0] + DP[i][2], DP[i-1][1] + DP[i][2]);
    }
```
    

<h4>소감</h4>

- 비교적 쉬운 DP

</details>

<details>
<summary><h4>플로이드</h4></summary>

|풀이 예상 시간|실제 소요 시간|
|:---:|:---:|
|45m|40m|

<h4>풀이</h4>

- 플로이드-워셜
1. (n+1) * (n+1) 사이즈의 2차원 배열을 선언한다
    
    단 arr[1][1]과 같은 경우 0으로, 이외의 경우에는 큰 값(10억)으로 지정

2. m개의 input을 받아 a to b의 경로의 최소 비용을 저장한다

```c++
    arr[a][b] = min(arr[a][b], c);
```

3. 플로이드-워셜 알고리즘을 통해 i to j 경로에서의 최소 비용을 찾는다

```c++
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if (arr[i][j] > arr[i][k] + arr[k][j]) {
                    arr[i][j] = arr[i][k] + arr[k][j];
                }
            }
        }
    }
```

<h4>소감</h4>

- 플로이드-워셜에서 방문하지 못하는 값은 큰 값으로 지정해야한다

</details>

<details>
<summary><h4>n단 논법</h4></summary>

|풀이 예상 시간|실제 소요 시간|
|:---:|:---:|
|20m|35m|

<h4>풀이</h4>

- map with DFS

1. input으로 들어오는 string의 첫 char와 마지막 char를 기반으로 `map<char, char>`를 구성한다
2. 맵에서 사용자가 입력한 `char - char` 매칭이 일어나는지 DFS로 탐색한다

```c++
void DFS(int current, int end) {
    if (m.find(current) == m.end()) {
        cout << "F\n";
        return;
    }
    
    if (m[current] == end) {
        cout << "T\n";
        return;
    } else {
        DFS(m[current], end);
    }
    
    return;
}
```

<h4>소감</h4>

- 오랜만의 `getline(cin, str)`

</details>

<details>
<summary><h4>요세푸스 문제</h4></summary>

|풀이 예상 시간|실제 소요 시간|
|:---:|:---:|
|30m|40m|

<h4>풀이</h4>

- queue

1. 1부터 N까지 queue에 추가한다.
2. `counter` 변수를 통해 현재 K번째 요소인지 판단한다

    - counter == K: queue의 front 출력 및 pop
    - counter != K: queue의 front를 queue의 끝으로 옮기고 pop

<h4>소감</h4>

- 어렵지 않은 문제였으나 알고리즘 분류 보기 전에는 깨닫지 못함

</details>

<details>
<summary><h4>여행가자</h4></summary>

|풀이 예상 시간|실제 소요 시간|
|:---:|:---:|
|45m|1h|

<h4>풀이</h4>

- Union-Find

i - j 노드 사이가 연결된 것들에 한해서 Union-Find를 수행한다

|함수|설명|
|:---:|:---|
|**tree_union(int x, int y)**|1. x와 y 각각의 루트를 찾는다<br>2. 루트가 동일하지 않을 경우 작은 x와 y값 중 작은 값으로 각각의 루트를 갱신한다|
|**find(int node)**|node가 속한 트리의 루트를 찾는다.

<h4>소감</h4>

- 처음 풀어보는 Union Find 문제!!!
- 문제를 잘 읽자... (처음에 문제 잘못 읽어서 Dijkstra로 접근함)


<h5>참고자료</h5>

[Link🔗](https://joodaram.tistory.com/72)

</details>

<details>
<summary><h4>N-Queen</h4></summary>

|풀이 예상 시간|실제 소요 시간|
|:---:|:---:|
|30m|35m|

<h4>풀이</h4>

- Back Tracking

1. N개의 Queen을 놓을 수 있는지 여부를 Back Tracking을 통해 체크한다.

```c++
void backTracking(int current) {
    if (current == N) { // Queen N개 놓기에 성공했다면 counter 1 증가 후 탈출
        counter += 1;
        return;
    } else {
        for(int i = 0; i < N; i++) {
            // 'current'번째 Queen을 i열에 놓는다.
            arr[current] = i;

            // 'current'번째 이전까지 놓은 Queen들과 'current'번째 Queen의 위치가 놓을 수 있는 곳이라면 계속해서 진행한다.
            if(isPossible(current)) {
                backTracking(current + 1);
            }
        }
    }
}

bool isPossible(int current) {
    for(int i = 0; i < current; i++) {
        // 서로 같은 열에 위치하거나, 대각선에 위치하는 경우 false 반환
        if (arr[i] == arr[current] || abs(arr[i] - arr[current]) == abs(i - current)) {
            return false;
        }
    }
    
    return true;
}
```

<h4>소감</h4>

- 이전에 푼 적이 있는데도 처음보는 것 같은 이 느낌이란...
- 이 문제를 통해서 DFS와 Back Tracking의 차이를 확실하게 알게 되었다.

|개념|설명|
|:---:|:---|
|DFS|깊이 우선 탐색으로 전체를 훑는다.|
|Back Tracking|탐색을 하되, 조건을 만족하지 않는 부분을 만나면 해당 부분 아래로는 더 이상 탐색을 진행하지 않는다 (트리의 가지치기같은 개념으로)|
</details>

<details>
<summary><h4>최소비용 구하기</h4></summary>

|풀이 예상 시간|실제 소요 시간|
|:---:|:---:|
|45m|45m|

<h4>풀이</h4>

- Dijkstra

1. input으로 받은 버스의 첫 시작 위치를 우선순위 큐에 넣는다.
    
    -> 단, 거리가 짧은 것이 먼저 앞으로 와야하므로, pair로 넣되 `{distance, 도착 지점}`으로 넣는다.

2. queue가 빌 때까지 특정 도시까지의 비용이 가장 작은 것들로 갱신한다.

```c++
    while(!pq.empty()) {
        pair<int, int> current = pq.top();
        pq.pop();

        // 이미 기록된 비용이 최소라면 continue 처리
        if (DP[current.second] < current.first) {
            continue;
        }

        for(int i = 0; i < v[current.second].size(); i++) {
            pair<int, int> next = v[current.second][i];

            int tempCost = next.first + DP[current.second];

            // 현재 기록된 비용보다 현재 도시(current.second)를 지나는게 비용이 더 적다면
            if (DP[next.second] > tempCost) {
                DP[next.second] = tempCost;
                pq.push({DP[next.second], next.second});
            }
        }
    }
```

<h4>소감</h4>

- Dijkstra에서 가장 기초라고 할 수 있는 문제. 기본기 빠이팅🔥

</details>

<details>
<summary><h4>제곱수의 합</h4></summary>

|풀이 예상 시간|실제 소요 시간|
|:---:|:---:|
|30m|45m|

<h4>풀이</h4>

- Dynamic Programming

1. dp[i]를 i라는 숫자를 제곱수로 1로 표현했을 때 필요한 숫자로 초기화한다.
2. for문을 통해  dp[1]부터 dp[N]에 이르기까지 제곱수를 활용한 경우 중에서 가장 작은 값으로 갱신한다.

<h4>소감</h4>

- 처음 봤을 때 DP라고 생각조차못한...
- 먼저 접근할 때에는 큰 제곱수부터 작은 제곱수를 순차적으로 빼는 형태를 생각했으나 아래의 참고자료처럼 `32`와 같은 예외가 존재함

```c++
// 틀린 풀이
int main() {
    int N;

    cin >> N;

    int target = 1;
    while(target * target < N) {
        target += 1;
    }

    int counter = 0;
    while(N != 0) {
        counter += N / (target * target);
        N = N % (target * target);
        target -= 1;
    }

    cout << counter;
}
```

<h5>참고자료</h5>

[Link🔗](https://velog.io/@matcha_/백준-1699-제곱수의-합-C-DP)
</details>

<details>
<summary><h4>비밀번호 제작</h4></summary>

|풀이 예상 시간|실제 소요 시간|
|:---:|:---:|
|1h|1h15m|

<h4>풀이</h4>

- 비트마스킹 with BFS

|arr[i]|숫자 i의 안전도|
|:---:|:---|

1. 각 숫자들의 안전도를 작은 값으로 초기화한다.
    
    단, input으로 받은 p값들에 대해선 안전도를 0으로 초기화하며, queue에 넣는다.

2. queue가 빌 때까지 1의 shift 연산을 통해 queue의 front값과 안전도가 1만큼 차이나는 숫자들을 queue에 넣는다.

    단, 해당 숫자(target)는 범위값 N보다 작아야하며, 이미 안전도가 `MIN`값이 아닌 다른 것으로 갱신된 경우에는 continue 처리

<h4>소감</h4>

- 비트 연산자 눈물이 나다
- 비트 연산과 BFS를 합쳐 사용한 예제는 처음 풀어보는 듯

<h5>참고자료</h5>

[Link🔗](https://imksh.com/47)

</details>

<details>
<summary><h4>선 긋기</h4></summary>

|풀이 예상 시간|실제 소요 시간|
|:---:|:---:|
|45m|20m|

<h4>풀이</h4>

- 라인 스위핑

1. vector에 선의 시작 지점과 끝 지점을 pair로 저장 후 sort
2. 선의 위치 관계에 따라 값을 갱신

|위치 관계|To do|
|:---:|:---|
|기존 선 --- 새로운 선|`counter`에 기존 선의 길이를 더한 후, 시작 & 끝 지점 갱신|
|새로운 선 S --- 기존 선S|선 시작 지점 갱신|
|기존 선(새로운 선과 겹침) --- 새로운 선 E|선 끝 지점 갱신|

<h4>소감</h4>

- 문제 풀기 전부터 라인 스위핑 관련 문제인걸 알고 있어서 빠르게 개념 학습 후 문제 풀이 시작함
- `cin&cout.tie(0)`와 `ios::sync_with_stdio(false)`를 잊지 말기

</details>

<details>
<summary><h4>트리와 쿼리</h4></summary>

|풀이 예상 시간|실제 소요 시간|
|:---:|:---:|
|45m|20m|

<h4>풀이</h4>

- Dynamic Programming

|Q|해당 자식 정점을 서브트리로 하는 트리의 노드의 수|
|:---:|:---|

1. 이차원 벡터를 통해 입력받은 간선 정보를 저장
2. `map<node번호, Node>`로 트리 형태 구성하기
3. `map`으로 만든 트리에서 DFS를 수행하며 각 노드의 하위 트리의 노드 수 세기

<h4>소감</h4>

- 이전에 풀어봤던 문제! 문제 예제까지 봤을 때는 막막하지만 힌트에서 설명해준 양식을 따라가면 생각보다 쉽게 풀 수 있는 문제였다.
- 각 노드 하위 트리에서 노드의 수(말이 어렵다)를 어떻게 셀 수 있지 고민했는데 DFS는 신입니다.
</details>


