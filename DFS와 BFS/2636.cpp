#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> pp;

int N, M;
vector<vector<int>> board, air;
pp dir[4] = {{-1, 0},  //상
             {1,  0},  //하
             {0,  -1}, //좌
             {0,  1}}; //우

void dfs(int r, int c) {
    air[r][c] = 1; //바깥 공기 표시
    for (int i = 0; i < 4; i++) {
        int nr = r + dir[i].first;
        int nc = c + dir[i].second;
        if ((nr >= 0) && (nr < N) && (nc >= 0) && (nc < M) && !air[nr][nc] && !board[nr][nc]) //범위 내에 있는 미방문 바깥 공기
            dfs(nr, nc);
    }
}

bool touchAir(int r, int c) { //바깥 공기와 닿아있는지 확인
    for (int i = 0; i < 4; i++) {
        if (air[r + dir[i].first][c + dir[i].second])
            return true;
    }
    return false;
}

int main() {
    int cheese = 0;

    cin >> N >> M;
    board.assign(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j]) //처음에 있던 치즈 수
                cheese++;
        }
    }
    int before_cheese, cnt = 0;
    while (true) {
        before_cheese = cheese; //직전 치즈의 수
        cnt++; //시간
        air.assign(N, vector<int>(M, 0));
        dfs(0, 0); //바깥 공기 표시
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (board[i][j] && touchAir(i, j)) { //녹게될 치즈
                    board[i][j] = 0;
                    cheese--;
                }
            }
        }
        if (cheese == 0) //더이상 치즈가 없으면
            break;
    }
    cout << cnt << '\n' << before_cheese;
}