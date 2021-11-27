#include <iostream>
#include <vector>

using namespace std;

bool flag;
vector<vector<char>> board;

bool find(int n, int r, int c) {
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    for (int i = 0; i < 4; i++) {
        int row = r, col = c;
        while (row >= 0 && row < n && col >= 0 && col < n && board[row][col] != 'O') {
            if (board[row][col] == 'S')
                return true;
            row += dr[i];
            col += dc[i];
        }
    }
    return false;
}

bool avoid(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 'T' && find(n, i, j)) //선생님에 대해 감시 범위 확인
                return false;
        }
    }
    return true;
}

void backtracking(int n, int idx, int cnt) {
    if (idx == n * n || cnt == 3) {
        if (avoid(n)) //피할 수 있는가?
            flag = true;
        return;
    }
    int row = idx / n;
    int col = idx % n;
    if (board[row][col] != 'X') //장애물 설치 불가
        return backtracking(n, idx + 1, cnt);
    board[row][col] = 'O'; //장애물 설치
    backtracking(n, idx + 1, cnt + 1);
    if (flag)
        return;
    board[row][col] = 'X'; //장애물 해제
    backtracking(n, idx + 1, cnt);
}

int main() {
    int n;

    cin >> n;
    board.assign(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> board[i][j];
    }
    backtracking(n, 0, 0);
    cout << (flag ? "YES" : "NO");
}