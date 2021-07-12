#include <iostream>
#include <vector>

using namespace std;

struct info {
    int r, c, d;
};

int max_fish = 0;
pair<int, int> direction[8] = {{-1, 0}, {-1, -1}, {0,  -1}, {1,  -1}, {1,  0}, {1,  1}, {0,  1}, {-1, 1}};

void moveFish(int idx, vector<info> &pos, vector<vector<int>> &board) {
    int row = pos[idx].r, col = pos[idx].c, dir = pos[idx].d; //행, 열, 방향
    do {
        int nr = row + direction[dir].first;
        int nc = col + direction[dir].second;
        if ((nr >= 0) && (nr < 4) && (nc >= 0) && (nc < 4) && (board[nr][nc] != 0)) { //범위내에 있고 상어 없으면
            swap(board[row][col], board[nr][nc]); //위치 교환
            pos[idx] = {nr, nc, dir}; //이번에 이동한 물고기 정보 갱신
            if (board[row][col] != -1) //빈공간으로 이동한게 아니라면(물고기와 위치를 바꾼거라면)
                pos[board[row][col]] = {row, col, pos[board[row][col]].d}; //바뀐 물고기 정보 갱신
            break;
        }
        dir = (dir + 1) % 8; //방향 바꾸기
    } while (dir != pos[idx].d);
}

void backtracking(int r, int c, int fish, vector<info> pos, vector<vector<int>> board) {
    fish += board[r][c]; //물고기 먹음
    int dir = pos[board[r][c]].d; //먹은 물고기의 방향
    pos[0] = {r, c, dir}; //상어 정보 갱신
    pos[board[r][c]].d = -1; //먹힌 물고기 갱신
    board[r][c] = 0; //상어 위치 표시
    for (int i = 1; i <= 16; i++) {
        if (pos[i].d != -1) //먹힌 물고기가 아니라면 이동
            moveFish(i, pos, board);
    }
    int nr = r, nc = c;
    while (true) { //범위 벗어날 때까지 해당 방향으로 이동
        nr += direction[dir].first;
        nc += direction[dir].second;
        if ((nr < 0) || (nr >= 4) || (nc < 0) || (nc >= 4)) //범위 벗어남
            break;
        if (board[nr][nc] != -1) { //물고기가 존재
            board[r][c] = -1; //원래 상어가 있던 곳은 빈공간으로
            backtracking(nr, nc, fish, pos, board);
        }
    }
    max_fish = max(max_fish, fish); //최댓값 갱신
}

int main() {
    vector<vector<int>> board(4, vector<int>(4));
    vector<info> pos(17);
    int a, b;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> a >> b;
            board[i][j] = a;
            pos[a] = {i, j, b - 1};
        }
    }
    backtracking(0, 0, 0, pos, board);
    cout << max_fish;
}