#include <iostream>
#include <queue>
#include <stack>
#include <utility>

using namespace std;

const int MAX = 100000;
pair<int, int> pos[MAX + 1];
queue<int> q;

void bfsPromising(int source, int dest) {
    if ((dest >= 0) && (dest <= MAX) && (pos[dest].first == 0)) { //방문한 적 없는 좌표
        pos[dest].first = pos[source].first + 1; //여기까지 오는데 걸리는 최소 시간
        pos[dest].second = source; //직전 위치
        q.push(dest);
    }
}

int bfs(int start, int end) {
    q.push(start);
    while (pos[end].first == 0) { //도착지점 방문하면 반복 종료
        int cur = q.front();
        q.pop();
        bfsPromising(cur, cur - 1); //X-1
        bfsPromising(cur, cur + 1); //X+1
        bfsPromising(cur, cur * 2); //X*2
    }
    return pos[end].first - 1; //시작점을 1로 시작했으니까 1을 빼줌
}

void printRoute(int end) {
    stack<int> s;
    int cur = end;

    while (cur != -1) { //시작점이 될 때까지 스택에 쌓기
        s.push(cur);
        cur = pos[cur].second;
    }
    while (!s.empty()) { //출력
        cout << s.top() << ' ';
        s.pop();
    }
}

int main() {
    int N, K;

    cin >> N >> K;
    pos[N].first = 1; //시작점 방문 표시
    pos[N].second = -1; //시작점의 직전 정점 초기화
    cout << bfs(N, K) << '\n';
    printRoute(K);
}