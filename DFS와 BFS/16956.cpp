#include <iostream>
#include <vector>

using namespace std;

bool promising(int r, int c, int row, int col, vector<vector<char>> &board) {
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    for (int i = 0; i < 4; i++) {
        int nr = row + dr[i];
        int nc = col + dc[i];
        if (nr >= 0 && nr < r && nc >= 0 && nc < c && board[nr][nc] == 'S')
            return false;
    }
    return true;
}

int main() {
    int r, c;
    string input;

    cin >> r >> c;
    vector<vector<char>> board(r, vector<char>(c));
    for (int i = 0; i < r; i++) {
        cin >> input;
        for (int j = 0; j < c; j++) {
            board[i][j] = input[j];
            if (board[i][j] == '.') //빈공간을 울타리로 채우기
                board[i][j] = 'D';
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (board[i][j] == 'W' && !promising(r, c, i, j, board)) { //늑대인데 인접한 곳에 양이 있음
                cout << 0;
                return 0;
            }
        }
    }
    cout << 1 << '\n';
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            cout << board[i][j];
        cout << '\n';
    }
}