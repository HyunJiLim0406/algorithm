#include <iostream>
#include <queue>

using namespace std;

const int MAX = 100000;
int pos[MAX + 1];
queue<int> q;

void bfsPromising(int source, int dest) {
    if ((dest >= 0) && (dest <= MAX) && (pos[dest] == 0)) { //방문한 적 없는 좌표
        pos[dest] = pos[source] + 1; //여기까지 오는데 걸리는 최소 시간
        q.push(dest);
    }
}

int bfs(int start, int end) {
    q.push(start);
    while (pos[end] == 0) { //도착지점 방문하면 반복 종료
        int cur = q.front();
        q.pop();
        bfsPromising(cur, cur - 1); //X-1
        bfsPromising(cur, cur + 1); //X+1
        bfsPromising(cur, cur * 2); //X*2
    }
    return pos[end] - 1; //시작점을 1로 시작했으니까 1을 빼줌
}

int main() {
    int N, K;

    cin >> N >> K;
    pos[N] = 1; //시작점 방문 표시
    cout << bfs(N, K);
}