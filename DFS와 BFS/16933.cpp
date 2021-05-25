#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;
typedef pair<int, int> pp;

struct status { //행, 열, 최단 거리, 벽을 부순 횟수, 낮 or 밤
    int r, c, d, b;
    bool is_day;
};
int N, M, K;
vector<vector<vector<int>>> visited; //방문여부
vector<vector<int>> board;
pp dir[4] = {{-1, 0},  //상
             {1,  0},  //하
             {0,  -1}, //좌
             {0,  1}}; //우

int bfs() {
    queue<status> q;
    visited[0][0][0] = 1; //방문 처리
    q.push({0, 0, 1, 0, true});
    while (!q.empty()) {
        int row = q.front().r;
        int col = q.front().c;
        int dist = q.front().d;
        int broken = q.front().b;
        bool is_day = q.front().is_day;
        q.pop();

        if ((row == N - 1) && (col == M - 1)) //종료 조건
            return dist;
        for (int i = 0; i < 4; i++) {
            int nr = row + dir[i].first;
            int nc = col + dir[i].second;
            if ((nr < 0) || (nr >= N) || (nc < 0) || (nc >= M)) //범위 체크
                continue;
            if ((board[nr][nc] == 0) && (visited[nr][nc][broken] == 0)) { //빈칸일 때
                visited[nr][nc][broken] = 1;
                q.push({nr, nc, dist + 1, broken, !is_day});
            } else if ((board[nr][nc] == 1) && (broken < K) &&
                       (visited[nr][nc][broken + 1] == 0)) { //벽이고, 아직 벽을 더 부술 수 있을 때
                if (is_day) { //낮이라면 부수고 이동
                    visited[nr][nc][broken + 1] = 1;
                    q.push({nr, nc, dist + 1, broken + 1, !is_day});
                } else //밤이라면 머무르기
                    q.push({nr, nc, dist + 1, broken, !is_day});
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string input;

    cin >> N >> M >> K;
    visited.assign(N, vector<vector<int>>(M, vector<int>(K + 1, 0)));
    board.assign(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++) {
        cin >> input;
        for (int j = 0; j < M; j++)
            board[i][j] = input[j] - '0';
    }
    cout << bfs();
}