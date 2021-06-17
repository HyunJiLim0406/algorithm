#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> pp;

struct shark_info { //상어 정보
    int r, c, s, d, z;
};

int R, C;
vector<vector<shark_info>> board; //각 위치별 상어의 상태
pp direction[4] = {{-1, 0},   //상
                   {1,  0},   //하
                   {0,  1},   //우
                   {0,  -1}}; //좌

int catchShark(int pos) { //해당 열에서 땅에 가장 가까운 상어
    int size = 0;
    for (int i = 0; i < R; i++) {
        if (board[i][pos].z) {
            size = board[i][pos].z;
            board[i][pos] = {0, 0, 0}; //상어 삭제
            break;
        }
    }
    return size;
}

shark_info nextMove(shark_info cur) { //상어 이동
    int row = cur.r; //행
    int col = cur.c; //열
    int dir = cur.d - 1; //방향
    for (int i = 0; i < cur.s; i++) { //속도 만큼 이동
        row += direction[dir].first;
        col += direction[dir].second;
        if ((row < 0) || (row >= R) || (col < 0) || (col >= C)) { //범위 벗어나면 방향 바꾸고 이동
            dir = (dir % 2 == 0) ? dir + 1 : dir - 1;
            row += direction[dir].first;
            col += direction[dir].second;
            i--;
        }
    }
    return {row, col, cur.s, dir + 1, cur.z};
}

vector<vector<shark_info>> nextBoard() {
    vector<vector<shark_info>> tmp(R, vector<shark_info>(C, {0, 0, 0})); //임시 배열
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (board[i][j].z) { //상어가 있으면
                shark_info next_pos = nextMove(board[i][j]); //이동
                int nr = next_pos.r;
                int nc = next_pos.c;
                if (next_pos.z > tmp[nr][nc].z) //기존에 위치한 상어보다 클 때만 투입
                    tmp[nr][nc] = next_pos;
            }
        }
    }
    return tmp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int M, r, c, s, d, z;

    cin >> R >> C >> M;
    board.assign(R, vector<shark_info>(C, {0, 0, 0}));
    while (M--) {
        cin >> r >> c >> s >> d >> z;
        if (d <= 2) //상어가 제자리로 돌아오게 되는 속력(상하)
            s %= 2 * (R - 1);
        else //상어가 제자리로 돌아오게 되는 속력(좌우)
            s %= 2 * (C - 1);
        board[r - 1][c - 1] = {r - 1, c - 1, s, d, z};
    }

    int result = 0;
    for (int i = 0; i < C; i++) { //낚시꾼 이동
        result += catchShark(i); //상어 잡기
        board = nextBoard(); //상어 이동
    }
    cout << result;
}