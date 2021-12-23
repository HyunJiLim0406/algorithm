#include <iostream>
#include <vector>

using namespace std;

void printMatrix(int n, vector<vector<char>> &matrix) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << matrix[i][j];
        cout << '\n';
    }
}

int cntBomb(int row, int col, int n, vector<vector<char>> &bomb) {
    int cnt = 0;
    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = col - 1; j <= col + 1; j++) {
            if (i < 0 || i >= n || j < 0 || j >= n) //범위 벗어남
                continue;
            if (bomb[i][j] == '*')
                cnt++;
        }
    }
    return cnt;
}

int main() {
    int n;
    string input;

    cin >> n;
    vector<vector<char>> bomb(n, vector<char>(n));
    vector<vector<char>> board(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        cin >> input;
        for (int j = 0; j < n; j++)
            bomb[i][j] = input[j];
    }
    for (int i = 0; i < n; i++) {
        cin >> input;
        for (int j = 0; j < n; j++)
            board[i][j] = input[j];
    }

    bool flag = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == '.') //선택하지 않음
                continue;
            if (bomb[i][j] == '*') { //지뢰 밟음
                flag = true;
                continue;
            }
            board[i][j] = cntBomb(i, j, n, bomb) + '0'; //지뢰 세기
        }
    }
    if (!flag) { //지뢰 안밟음
        printMatrix(n, board);
        return 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (bomb[i][j] == '*')
                cout << bomb[i][j];
            else
                cout << board[i][j];
        }
        cout << '\n';
    }
}