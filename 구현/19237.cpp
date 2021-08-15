#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

struct info {
    bool is_in; //안에 있나
    int dir, row, col; //방향, 열, 행
    int pri[4][4]; //우선순위
};

int N, M, k;
vector<info> shark;
vector<vector<int>> board, scent;
pair<int, int> direction[4] = {{-1, 0},  //상
                               {1,  0},  //하
                               {0,  -1}, //좌
                               {0,  1}}; //우

void moveNext(int idx) {
    if (!shark[idx].is_in) //존재하는 상어가 아님
        return;
    vector<tuple<int, int, int>> candi;
    int row = shark[idx].row;
    int col = shark[idx].col;
    for (int i = 0; i < 4; i++) {
        int nd = shark[idx].pri[shark[idx].dir - 1][i]; //방향
        int nr = row + direction[nd - 1].first;
        int nc = col + direction[nd - 1].second;
        if (nr < 0 || nr >= N || nc < 0 || nc >= N) //범위 벗어남
            continue;
        if (board[nr][nc] == idx) //본인의 냄새가 있는 곳이면 후보에 넣기
            candi.emplace_back(nd, nr, nc);
        if (board[nr][nc] == 0) { //빈공간이면 정보 갱신
            shark[idx].dir = nd;
            shark[idx].row = nr;
            shark[idx].col = nc;
            return;
        }
    }
    //본인의 냄새가 있는 곳으로 가기
    shark[idx].dir = get<0>(candi[0]);
    shark[idx].row = get<1>(candi[0]);
    shark[idx].col = get<2>(candi[0]);
}

void markPos(int idx) {
    if (!shark[idx].is_in) //존재하는 상어가 아님
        return;
    int row = shark[idx].row;
    int col = shark[idx].col;
    if (board[row][col] == 0 || board[row][col] == idx) { //본인의 냄새가 있는 곳이나 빈공간
        board[row][col] = idx;
        scent[row][col] = k + 1;
    } else //다른 상어가 이미 존재하면 쫓겨남
        shark[idx].is_in = false;
}

void erasePos() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (scent[i][j] == 0)
                continue;
            scent[i][j]--; //냄새 지우기
            if (scent[i][j] == 0) //냄새가 다 사라짐
                board[i][j] = 0;
        }
    }
}

bool isEnd() { //모든 상어 쫓겨났는지 확인
    for (int i = 2; i <= M; i++) {
        if (shark[i].is_in)
            return false;
    }
    return true;
}

int main() {
    cin >> N >> M >> k;
    board.assign(N, vector<int>(N));
    scent.assign(N, vector<int>(N));
    shark.assign(M + 1, {});
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            if (board[i][j]) {
                shark[board[i][j]].row = i;
                shark[board[i][j]].col = j;
                scent[i][j] = k;
            }
        }
    }
    for (int i = 1; i <= M; i++) {
        shark[i].is_in = true;
        cin >> shark[i].dir;
    }
    for (int i = 1; i <= M; i++) {
        for (int j = 0; j < 4; j++) {
            for (int l = 0; l < 4; l++)
                cin >> shark[i].pri[j][l];
        }
    }

    int sec = 1;
    while (sec <= 1000) {
        for (int i = 1; i <= M; i++) //상어 이동
            moveNext(i);
        for (int i = 1; i <= M; i++) //새로운 위치 표시
            markPos(i);
        erasePos(); //냄새 지우기
        if (isEnd()) //반복문 마치는지 확인
            break;
        sec++;
    }
    cout << ((sec == 1001) ? -1 : sec);
}