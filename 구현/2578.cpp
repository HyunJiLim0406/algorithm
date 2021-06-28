#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> board(5, vector<int>(5));

pair<int, int> findPos(int num) { //위치 찾기
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (board[i][j] == num)
                return make_pair(i, j);
        }
    }
    return make_pair(-1, -1);
}

bool isHorizontal(pair<int, int> pos) {
    for (int i = 0; i < 5; i++) {
        if (board[pos.first][i])
            return false;
    }
    return true;
}

bool isVertical(pair<int, int> pos) {
    for (int i = 0; i < 5; i++) {
        if (board[i][pos.second])
            return false;
    }
    return true;
}

bool isDiagonal1() {
    for (int i = 0; i < 5; i++) {
        if (board[i][i])
            return false;
    }
    return true;
}

bool isDiagonal2() {
    for (int i = 0; i < 5; i++) {
        if (board[i][4 - i])
            return false;
    }
    return true;
}

int main() {
    int input, cnt = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++)
            cin >> board[i][j];
    }
    for (int i = 0; i < 25; i++) {
        cin >> input;
        pair<int, int> pos = findPos(input);
        board[pos.first][pos.second] = 0; //지움
        if (isHorizontal(pos)) //가로 빙고
            cnt++;
        if (isVertical(pos)) //세로 빙고
            cnt++;
        if (pos.first == pos.second && isDiagonal1()) //대각선1
            cnt++;
        if (pos.first + pos.second == 4 && isDiagonal2()) //대각선2
            cnt++;
        if (cnt >= 3) {
            cout << i + 1;
            break;
        }
    }
}