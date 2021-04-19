#include <iostream>
#include <deque>

using namespace std;

const int MAX = 100000;
int pos[MAX + 1];
deque<int> dq;

void bfsPromising(int source, int dest, int flag) {
    if ((dest >= 0) && (dest <= MAX) && (pos[dest] == 0)) { //방문한 적 없는 좌표
        if (flag) {
            pos[dest] = pos[source]; //여기까지 오는데 걸리는 최소 시간
            dq.push_front(dest); //앞에 삽입
        }
        else {
            pos[dest] = pos[source] + 1; //여기까지 오는데 걸리는 최소 시간
            dq.push_back(dest); //뒤에 삽입
        }
    }
}

int bfs(int start, int end) {
    dq.push_back(start);
    while (!dq.empty()) { //도착지점 방문하면 반복 종료
        int cur = dq.front();
        dq.pop_front();
        if (cur == end)
            return pos[end] - 1;
        //순서 중요
        bfsPromising(cur, cur * 2, 1); //X*2
        bfsPromising(cur, cur + 1, 0); //X+1
        bfsPromising(cur, cur - 1, 0); //X-1
    }
    return 0;
}

int main() {
    int N, K;

    cin >> N >> K;
    pos[N] = 1; //시작점 방문 표시
    cout << bfs(N, K);
}