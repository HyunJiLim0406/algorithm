#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct info {
    int r, c, t;
};

vector<vector<char>> board;
pair<int, int> dir[4] = {{-1, 0},  //상
                         {1,  0},  //하
                         {0,  -1}, //좌
                         {0,  1}}; //우

bool promising(int N, int sr, int er, int sc, int ec) { //해당 좌표가 범위를 벗어나거나 1을 포함하는지 확인
    for (int i = sr; i <= er; i++) {
        for (int j = sc; j <= ec; j++) {
            if (i < 0 || i >= N || j < 0 || j >= N || board[i][j] == '1')
                return false;
        }
    }
    return true;
}

int bfs(int N, info start, info end) {
    queue<info> q;
    vector<vector<vector<int>>> dist(N, vector<vector<int>>(N, vector<int>(2, 0)));
    dist[start.r][start.c][start.t] = 1;
    q.push(start);
    while (!q.empty()) {
        int row = q.front().r; //행
        int col = q.front().c; //열
        int d = q.front().t; //방향
        int distance = dist[row][col][d];
        q.pop();

        if (row == end.r && col == end.c && d == end.t) //도착
            return distance - 1;
        for (int i = 0; i < 4; i++) {
            int nr = row + dir[i].first;
            int nc = col + dir[i].second;
            if (d == 0 && !promising(N, nr - 1, nr + 1, nc, nc)) //세로 모양일 때 범위 확인
                continue;
            if (d == 1 && !promising(N, nr, nr, nc - 1, nc + 1)) //가로 모양일 때 범위 확인
                continue;
            if (dist[nr][nc][d]) //방문 체크
                continue;
            dist[nr][nc][d] = distance + 1;
            q.push({nr, nc, d});
        }
        if (promising(N, row - 1, row + 1, col - 1, col + 1) && !dist[row][col][(d + 1) % 2]) { //회전
            dist[row][col][(d + 1) % 2] = distance + 1;
            q.push({row, col, (d + 1) % 2});
        }
    }
    return 0; //이동 불가
}

int main() {
    int N;
    string input;
    bool is_start = false, is_end = false;
    info start{}, end{};

    cin >> N;
    board.assign(N, vector<char>(N));
    for (int i = 0; i < N; i++) {
        cin >> input;
        for (int j = 0; j < N; j++) {
            board[i][j] = input[j];
            if (board[i][j] == 'B' && !is_start) { //시작점
                is_start = true;
                if (j + 1 < N && input[j + 1] == 'B') //가로
                    start = {i, j + 1, 1};
                else //세로
                    start = {i + 1, j, 0};
            }
            if (board[i][j] == 'E' && !is_end) { //도착점
                is_end = true;
                if (j + 1 < N && input[j + 1] == 'E') //가로
                    end = {i, j + 1, 1};
                else //세로
                    end = {i + 1, j, 0};
            }
        }
    }
    cout << bfs(N, start, end);
}