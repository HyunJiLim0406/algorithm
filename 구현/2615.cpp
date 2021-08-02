#include <iostream>

using namespace std;

int board[19][19];
pair<int, int> dir[4] = {{0,  1},
                         {1,  0},
                         {1,  1},
                         {-1, 1}};

bool isEnd(int r, int c, int d, int num) {
    int cnt = 0, nr = r - dir[d].first, nc = c - dir[d].second;
    while (r >= 0 && r < 19 && c >= 0 && c < 19 && board[r][c] == num) {
        cnt++;
        r += dir[d].first;
        c += dir[d].second;
    }
    return cnt == 5 && (nr < 0 || nr >= 19 || nc < 0 || nc >= 19 || board[nr][nc] != num); //이전 방향
}

int main() {
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++)
            cin >> board[i][j];
    }
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if (!board[i][j])
                continue;
            for (int k = 0; k < 4; k++) { //4개의 방향에 대해 돌 세어보기
                if (isEnd(i, j, k, board[i][j])) {
                    cout << board[i][j] << '\n' << i + 1 << ' ' << j + 1;
                    return 0;
                }
            }
        }
    }
    cout << 0;
}