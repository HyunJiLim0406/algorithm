#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;
typedef pair<int, int> pp;

struct status { //행, 열, 최단 거리, 벽을 부순 횟수
    int r, c, d, b;
};
int N, M, K;
vector<vector<int>> visited; //방문여부
vector<vector<int>> board;
pp dir[4] = {{-1, 0},  //상
             {1,  0},  //하
             {0,  -1}, //좌
             {0,  1}}; //우

int bfs() {
    queue<status> q;
    visited[0][0] = 0; //방문처리
    q.push({0, 0, 1, 0});
    while (!q.empty()) {
        int row = q.front().r;
        int col = q.front().c;
        int dist = q.front().d;
        int broken = q.front().b;
        q.pop();

        if ((row == N - 1) && (col == M - 1)) //종료 조건
            return dist;
        for (int i = 0; i < 4; i++) {
            int nr = row + dir[i].first;
            int nc = col + dir[i].second;
            if ((nr < 0) || (nr >= N) || (nc < 0) || (nc >= M)) //범위 체크
                continue;
            if ((board[nr][nc] == 0) && (visited[nr][nc] > broken)) { //빈칸일 때
                visited[nr][nc] = broken;
                q.push({nr, nc, dist + 1, broken});
            } else if ((board[nr][nc] == 1) && (broken < K) &&
                       (visited[nr][nc] > (broken + 1))) { //벽이고, 아직 벽을 더 부술 수 있을 때
                visited[nr][nc] = broken + 1;
                q.push({nr, nc, dist + 1, broken + 1});
            }
        }
    }
    return -1;
}

int main() {
    string input;

    cin >> N >> M >> K;
    board.assign(N, vector<int>(M, 0));
    visited.assign(N, vector<int>(M, 1e9));
    for (int i = 0; i < N; i++) {
        cin >> input;
        for (int j = 0; j < M; j++)
            board[i][j] = input[j] - '0';
    }
    cout << bfs();
}