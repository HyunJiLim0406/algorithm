#include <iostream>
#include <vector>
#include <deque>

using namespace std;
typedef pair<int, int> pp;

struct info { //행, 열, 방향
    int r, c, d;
};

vector<info> status; //각 말의 위치와 방향
vector<vector<int>> board; //체스판
vector<vector<deque<int>>> pos; //체스판의 각 위치에 말들이 어떻게 있는지
pp dir[4] = {{0,  1},  //우
             {0,  -1}, //좌
             {-1, 0},  //상
             {1,  0}}; //하

void movePiece(info piece, int idx, bool flag) {
    deque<int> tmp;
    int row = piece.r, col = piece.c;
    int nr = row + dir[piece.d].first, nc = col + dir[piece.d].second;
    if (board[nr][nc] != 2) { //이동할 곳이 파란색이 아니라면
        while (!pos[row][col].empty()) { //목표로 하는 말이 나올 때까지 빼서 덱에 넣기
            tmp.push_front(pos[row][col].back());
            pos[row][col].pop_back();
            if (tmp.front() == idx)
                break;
        }
        if (board[nr][nc] == 0) { //하얀색
            while (!tmp.empty()) { //순서대로 넣으면서 각 말의 위치 갱신
                pos[nr][nc].push_back(tmp.front());
                status[tmp.front()].r = nr;
                status[tmp.front()].c = nc;
                tmp.pop_front();
            }
        } else if (board[nr][nc] == 1) { //빨간색
            while (!tmp.empty()) { //반대로 넣으면서 각 말의 위치 갱신
                pos[nr][nc].push_back(tmp.back());
                status[tmp.back()].r = nr;
                status[tmp.back()].c = nc;
                tmp.pop_back();
            }
        }
    } else if (!flag) { //파란색인데 아직 방향을 바꾸지 않음
        piece.d = (piece.d % 2 == 0) ? piece.d + 1 : piece.d - 1; //방향 바꾸기
        status[idx] = piece; //갱신
        movePiece(status[idx], idx, true); //새로운 곳에 대해 다시 해보기
    }
}

bool isFinish(int N) { //종료조건 충족 확인
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (pos[i][j].size() >= 4)
                return true;
        }
    }
    return false;
}

int main() {
    int N, K, r, c, d;

    cin >> N >> K;
    status.assign(K, {0, 0, 0});
    board.assign(N + 2, vector<int>(N + 2, 2));
    pos.assign(N + 2, vector<deque<int>>(N + 2));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++)
            cin >> board[i][j];
    }
    for (int i = 0; i < K; i++) {
        cin >> r >> c >> d;
        status[i] = {r, c, d - 1};
        pos[r][c].push_back(i); //위치 입력
    }
    for (int i = 1; i <= 1000; i++) {
        for (int j = 0; j < K; j++) {
            movePiece(status[j], j, false);
            if (isFinish(N)) { //말을 옮길 때마다 확인
                cout << i;
                return 0;
            }
        }
    }
    cout << -1;
}