# 위상 정렬
Thanks to jason9319

이 문서의 내용은 [http://jason9319.tistory.com/93](http://jason9319.tistory.com/93) 을 요약, 정리한 것입니다. 매우 좋은 글이니 자세한 설명을 원하시는 분은 원글을 읽어보세요.
## DFS와 스택을 이용한 구현 방법
dfs가 끝나는 순서대로 스택에 넣는다.

([줄세우기](https://www.acmicpc.net/problem/2252) 문제의 정답 코드)
```cpp
#include <bits/stdc++.h>

using namespace std;

vector<int> v[32001];
bool check[32001];
stack<int> s;

void dfs(int i)
{
    check[i] = true;
    for (auto j: v[i]) {
        if (!check[j]) {
            dfs(j);
        }
    }
    s.push(i);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int n, m;
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }

    for (int i=1; i<=n; i++) {
        if (!check[i]) {
            dfs(i);
        }
    }

    while (!s.empty()) {
        cout << s.top() << ' ';
        s.pop();
    }
}
```
## BFS와 큐를 이용한 구현 방법 (Indegree 수)
1. in 배열에 각 노드의 indegree 수를 저장한다.
1. indegree 가 0인 노드들을 큐에 넣는다.
1. 큐의 가장 앞에 있는 노드를 꺼내 bfs로 연결된 노드들의 indegree를 1씩 감소시켜주며 만약 이때 indegree가 0이 되면 큐에 넣어준다.
1. 큐가 다 비워질때까지 3을 반복한다.

([문제집](https://www.acmicpc.net/problem/1766) 문제의 정답 코드)
```cpp
#include <bits/stdc++.h>

using namespace std;

vector<int> v[32001];
int in[32001];
priority_queue<int, vector<int>, greater<>> q;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int n, m;
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        in[b]++;
    }

    for (int i=1; i<=n; i++) {
        if (!in[i]) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int now = q.top();
        q.pop();
        cout << now << ' ';
        for (auto &j: v[now]) {
            in[j]--;
            if (!in[j]) {
                q.push(j);
            }
        }
    }
}
```

## 위상 정렬을 하면서 사이클이 있는지 체크하기
### 1. DFS와 스택을 이용한 구현에서
이전에 방문한 적이 있는데 아직 dfs가 끝나지 않은 노드가 있다면 사이클이 존재한다는 뜻이다.
```cpp
void dfs(int i)
{
    check[i] = true;
    for (auto j: v[i]) {
        if (!check[j]) {
            dfs(j);
        }
        else if (!finished[j]) {
            hasCycle = true;
        }
    }
    finished[i] = true;
    s.push(i);
}
```
### 2. BFS와 큐를 이용한 구현에서

사이클이 없으려면 큐가 다 비워졌을 때 모든 노드의 indegree가 0이 되어야 한다.

## 문제

|번호|문제|소스코드|난이도|출처|
|:-:|:-:|:-:|:-:|:-:|