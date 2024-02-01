# [24.01.29~24.02.02 24:00] 4주차 스터디

|기간|24.01.29~24.02.02 24:00|
|:---:|:---|
|3주차 연습문제|[등수 매기기](https://www.acmicpc.net/problem/2012)|
|링크|[1. 미로 만들기🔗](https://www.acmicpc.net/problem/2665)<br>[2. 일요일 아침의 데이트🔗](https://www.acmicpc.net/problem/1445)<br>[3. 수열🔗](https://www.acmicpc.net/problem/2559)<br>[4. 회문🔗](https://www.acmicpc.net/problem/17609)<br>[5. 01타일🔗](https://www.acmicpc.net/problem/1904)|

|문제 풀기 전 체감 난이도|일요일 아침의 데이트 > 미로 만들기 > 01타일 > 수열 > 등수 매기기|
|:---:|:---|
|문제 푼 후 난이도|일요일 아침의 데이트 > 미로 만들기 > 01타일 > 수열 > 등수 매기기|
- 🔥Dijkstra BFS DP 슬라이딩 윈도우🔥

<details>
<summary><h4>등수 매기기</h4></summary>

|풀이 예상 시간|실제 소요 시간|
|:---:|:---:|
|15m|35m|

<h4>풀이</h4>

- vector 

1. input으로 받은 N개의 수를 숫자를 정렬한다.
2. 정렬된 vector의 값과 1부터 하나씩 늘려가며 두 값의 절대값 차이(abs)를 구한다
    
    -> 단!!! int타입으로는 범위를 초과할 수 있으니 `result`는 `long long` 타입으로 선언하자

```c++
for(int i = 0; i < N; i++) {
        result += abs(v[i]-(i+1));
    }
```

<h4>소감</h4>

- 50000 * 50000 = 2500000000(25억)

</details>

<details>
<summary><h4>미로 만들기</h4></summary>

|풀이 예상 시간|실제 소요 시간|
|:---:|:---:|
|1h|45m|

<h4>풀이</h4>

- BFS

1. input으로 들어오는 값들을 string -> int로 치환 (숫자를 띄어쓰기 없이 입력받기 때문)

```c++
void stringToInt(string s, int r) {
    for(int i = 0; i < s.size(); i++) {
        arr[r][i] = s[i] - '0';
    }
}
```

2. 각 지점(r, c)에서 상하좌우로 탐색하며 방의 색상 변경 여부 확인하기

    -> `visited[r][c]` = 해당 지점(r,c)에 도달하기까지 얼마나 적게 방의 색상을 변경해야만 했는가
    -> 시작 지점(0,0)을 제외한 모든 지점은 큰 값으로 할당하기

```c++
void Solve() {
    queue<Position> q;
    q.push(Position(0, 0));
    
    for(int i = 0; i < 51; i++) {
        for(int j = 0; j < 51; j++) {
            visited[i][j] = 251;
        }
    }
    
    visited[0][0] = 0;
    
    while(!q.empty()) {
        Position current = q.front();
        q.pop();
        
        for(int i = 0; i < 4; i++) {
            int tr = current.r + dr[i];
            int tc = current.c + dc[i];
                
            if (tr < 0 || tc < 0 || tr >= N || tc >= N) {
                continue;
            }
            
            // deltaVal == 1 : 방의 색상을 바꾼다
            // deltaVal == 0 : 방의 색상을 바꾸지 않는다
            int deltaVal = 1 - arr[tr][tc];
            
            // 가야하는 지점(tr, tc) 지점의 값이 현재 위치(r, c)에서 deltaVal을 더한 것보다 큰 경우
            // 가야하는 지점이 색상 변경이 더 많이 일어나야하는 경우
            // 현재 지점까지의 (최소) 색상 변경 횟수 + deltaVal로 (tr, tc)의 값을 치환한다.
            if(visited[tr][tc] > visited[current.r][current.c] + deltaVal) {
                visited[tr][tc] = visited[current.r][current.c] + deltaVal;
                q.push(Position(tr, tc));
            }
            
        }
    }
}
```

<h4>소감</h4>

- 처음에 BFS로 접근했다가 '앗 근데 어떻게 제일 최단거리로 왔는지 저장하지?' 생각하곤 DFS로 바꿨으나 결국 BFS였다...
- `memset` 공부하자.
- 초기화를 잊지말자

</details>

<details>
<summary><h4>일요일 아침의 데이트</h4></summary>

|풀이 예상 시간|실제 소요 시간|
|:---:|:---:|
|45m|1h 15m|

<h4>풀이</h4>

- Dijkstra

1. input 문자열을 문자로 분해해서 `map`에 저장
    
    -> 단, 나중에 위치 비교를 위해 시작 지점과 도착 지점을 미리 구분하기

    ```c++
    void stringToChar(string s, int r) {
        for(int i = 0; i < s.size(); i++) {
            map[r][i] = s[i];
            if (map[r][i] == 'S') {
                startPos = Position(r, i);
            } else if (map[r][i] == 'F') {
                endPos = Position(r, i);
            }
        }
    }
    ```

2. `priority_queue`를 활용해 각 위치에서 상하좌우 방향으로 쓰레기가 있는지 탐색한다
<while문: 쓰레기 칸 & 상하좌우 쓰레기 여부 탐색>
    
    현재 위치를 기준으로 상하좌우 탐색 (단, 방문한 곳은 재방문하지 않는다)

    1. `특정 위치 == 'g'` : 해당 위치에 쓰레기가 있다면, 쓰레기가 있는(`on`) 위치 +1
    2. `특정 위치 == '.'` : 해당 위치에 쓰레기가 없다면, '그 주변에' 쓰레기가 있는지 없는지 탐색
        
        -> 주변에 쓰레기가 있다면, 쓰레기가 주변에 있는(`between`) 위치 +1 후 pq에 넣기
        -> 주변에 쓰레기가 없다면, 쓰레기가 없는 상태 그대로 pq에 넣기
        
        ```c++
        if (trashCheck) {
            pq.push({{onTrash, betweenTrash + 1}, next});
        } else {
            pq.push({{onTrash, betweenTrash}, next});
        }
        ```

    3. 방문이 끝난 위치에 대해선 더 이상 방문하지 않도록 dist값 더하기
    ```c++
    dist[next.r][next.c] = dist[next.r][next.c] + 1;
    ```

<h4>소감</h4>

- 어렵다 어려워 빠이팅이다 진짜
- 처음에 [[백준 GOLD.4] 2665 - 미로만들기](https://www.acmicpc.net/problem/2665)와 비슷하다고 생각했는데 전혀 아니었다! 어렴풋이 그래프인가? 하긴 했는데 <h3>Dijkstra!!!!!</h3>
- `priority_queue` 선언이 너무 길어지는 것 같아서 별개의 `Position` 구조체를 만든 것 까지는 좋았으나, 우선순위 할당을 위한 비교 연산이 타입 매칭이 되지 않으면 컴파일 에러가 발생했다. 시간이 여유롭지 않은 상황에서는 구조체를 만들기보다는 길게 쓰는게 나으려나? 고민스럽도다. 구현은 아래와 같다.

    ```c++
    struct Position {
        int r;
        int c;
        
        Position(int _r, int _c) : r(_r), c(_c) { }
    };

    struct Compare {
        bool operator()(const pair<pair<int, int>, Position>& p1, const pair<pair<int, int>, Position>& p2) {
            if (p1.first.first != p2.first.first) {
                return p1.first.first > p2.first.first;
            }
            if (p1.first.second != p2.first.second) {
                return p1.first.second > p2.first.second;
            }
            return false;
        }
    };

    // 실제 priority_queue에서 사용 시
    priority_queue<pair<pair<int, int>, Position>, vector<pair<pair<int, int>, Position>>, Compare> pq;
    ```

<h5>참고자료</h5>

[Link🔗](https://go2gym365.tistory.com/213)

</details>

<details>
<summary><h4>수열</h4></summary>

|풀이 예상 시간|실제 소요 시간|
|:---:|:---:|
|30m|25m|

<h4>풀이</h4>

- 슬라이딩 윈도우

1. 문제에서 요구하는 K에 해당하는 숫자만큼 입력을 받은 후 `currentMax`로 초기화한다.
2. 이후 K번째 idx부터 N-1번째 idx에 이르기까지 가장 K사이즈의 윈도우의 위치를 옮기며 최대값을 갱신한다.

```c++
    for(int i = K; i < N; i++) {
        cin >> arr[i];
        temp = temp - arr[throwNumIdx] + arr[i];
        currentMax = max(temp, currentMax);
        throwNumIdx += 1;
    }
```

<h4>소감</h4>

- 이전 주차에 풀었던 [DNA 비밀번호](https://www.acmicpc.net/problem/12891)와 상당히 유사했던 문제라 비교적 쉽게 풀었다.

</details>

<details>
<summary><h4>회문</h4></summary>

|풀이 예상 시간|실제 소요 시간|
|:---:|:---:|
|45m|50m|

<h4>풀이</h4>

- 투 포인터

1. 각각의 input string에 대해 회문 여부를 판별한다
    
    -> **단, `while`문 내부에서 `1의 경우`, 한 글자를 제거했을 때에만  회문으로 간주하므로 `firstCall` 두 글자 이상을 제거했을 때 회문이 만들어지는 경우와 재귀에 의한 시간초과를 방지하자.**

```c++
int isPalindrome(int left, int right, bool firstCall) {
    while (left < right) {
        if (s[left] != s[right]) {
            if (firstCall) {
                if (isPalindrome(left + 1, right, false) == 0 || isPalindrome(left, right - 1, false) == 0) {
                   return 1;
                }   
            }
            return 2;
        }
        
        left += 1;
        right -= 1;
    }
    return 0;
}
```


<h5>시간초과 풀이</h5>

- 최대 30개의 10만번 반복 = 300만번 연산이면 괜찮다고 생각했지만, 반복되는 `substr`과 `reverse`로 시간 초과

```c++
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int isPalindrome(string s) {
    // 0
    int len = s.size();
    int half = len / 2;
    string s1 = s.substr(0, half);
    string s2;
    
    if (len % 2 == 0) {
        s2 = s.substr(half, half); 
    } else {
        s2 = s.substr(half+1, half);
    }
    
    reverse(s2.begin(), s2.end());
    if (s1 == s2) {
        return 0;
    }
    
    // 1
    string temp;
    len = s.size() - 1;
    half = len / 2;
    for(int i = 0; i < len - 1; i++) {
        temp = s.substr(0, i);
        temp += s.substr(i+1, len - i);
        s1 = temp.substr(0, half);
        if (len % 2 == 0) {
            s2 = temp.substr(half, half); 
        } else {
            s2 = temp.substr(half+1, half);
        }
        reverse(s2.begin(), s2.end());
        if (s1 == s2) {
            return 1;
        }
    }
    
    // 2
    return 2;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    
    string temp;
    for(int i = 0; i < T; i++) {
        cin >> temp;
        cout << isPalindrome(temp) << '\n';
    }

    return 0;
}

```

<h4>소감</h4>

- 시간초과가 난 다음에 투 포인터인가? 고민했으나, 알고보니 머릿속에선 이분탐색을 생각하고 있었다... 개념과 풀이를 매칭하자!

<h5>참고자료</h5>

[Link🔗](https://coder38611.tistory.com/124)

</details>

<details>
<summary><h4>01타일</h4></summary>

|풀이 예상 시간|실제 소요 시간|
|:---:|:---:|
|45m|1h|

<h4>풀이</h4>

- DP (fibonacci)

1. Dynamic Programming을 통해 1000000번째 피보나치 수열까지 미리 구해둔다.
    
    -> 단, 너무 큰 피보나치 수열의 경우 long long 타입을 넘어서기 때문에 미리 15746으로 나누어준다.

|N자리 수|경우|Total|
|:---:|:---:|:---:|
|1|1|1|
|2|00<br>11|2|
|3|001<br>100<br>111|3|
|4|0011<br>1001<br>1100<br>1111<br>0000|5|

<h4>소감</h4>

- 와... 피보나치 수열이다.

</details>


