#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

map<int, int> ladder_or_snake; //사다리와 뱀 정보

int bfs() {
    queue<int> q;
    vector<int> dist; //거리 정보
    dist.assign(101, -1);

    dist[1] = 0; //시작점 초기화
    q.push(1);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == 100) //100에 도달하면 dist 반환
            return dist[cur];
        for (int i = (cur + 1); i <= (cur + 6); i++) { //1~6 주사위 굴리기
            if (dist[i] == -1) { //미방문 좌표
                dist[i] = dist[cur] + 1;
                if (ladder_or_snake[i]) { //사다리 또는 뱀이 있다면
                    int move = ladder_or_snake[i];
                    if (dist[move] == -1) { //이동하게 된 위치 큐에 넣기
                        dist[move] = dist[i];
                        q.push(move);
                    }
                } else //없다면 그냥 i를 큐에 넣기
                    q.push(i);
            }
        }
    }
    return 0;
}

int main() {
    int N, M, x, y;

    cin >> N >> M;
    for (int i = 0; i < N + M; i++) {
        cin >> x >> y;
        ladder_or_snake[x] = y;
    }
    cout<<bfs();
}