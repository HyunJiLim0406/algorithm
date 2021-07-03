#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;
typedef pair<int, int> pp;

struct info { //행, 열, 거리, 보유 열쇠 상태
    int r, c, d, s;
};

int N, M;
vector<vector<char>> board;
vector<vector<vector<bool>>> visited;
pp dir[4] = {{-1, 0},  //상
             {1,  0},  //하
             {0,  -1}, //좌
             {0,  1}}; //우

int bfs(info start) {
    queue<info> q;
    visited[start.r][start.c][start.s] = true; //시작점 초기화
    q.push(start);
    while (!q.empty()) {
        int row = q.front().r;
        int col = q.front().c;
        int dist = q.front().d;
        int status = q.front().s;
        q.pop();

        if (board[row][col] == '1') //출구
            return dist;
        for (int i = 0; i < 4; i++) {
            int nr = row + dir[i].first;
            int nc = col + dir[i].second;
            int ns = status;
            if ((nr < 0) || (nr >= N) || (nc < 0) || (nc >= M) || (board[nr][nc] == '#')) //범위를 벗어나거나 벽
                continue;
            if (isupper(board[nr][nc]) && !(status & (1 << (board[nr][nc] - 'A')))) //문인데 열쇠가 없음
                continue;
            if (islower(board[nr][nc])) //열쇠라면 획득처리
                ns |= (1 << (board[nr][nc] - 'a'));
            if (!visited[nr][nc][ns]) { //미방문 정점
                visited[nr][nc][ns] = true; //방문 처리
                q.push({nr, nc, dist + 1, ns});
            }
        }
    }
    return -1; //출구 찾지 못함
}

int main() {
    string input;
    info start{};

    cin >> N >> M;
    board.assign(N, vector<char>(M));
    visited.assign(N, vector<vector<bool>>(M, vector<bool>(1 << 6))); //열쇠는 a-f 6개
    for (int i = 0; i < N; i++) {
        cin >> input;
        for (int j = 0; j < M; j++) {
            board[i][j] = input[j];
            if (board[i][j] == '0') //시작점
                start = {i, j, 0, 0};
        }
    }
    cout << bfs(start);
}