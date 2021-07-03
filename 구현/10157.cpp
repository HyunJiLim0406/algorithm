#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> board;
pair<int, int> dir[4] = {{-1, 0},   //상
                         {0,  1},   //우
                         {1,  0},   //하
                         {0,  -1}}; //좌

pair<int, int> findPos(int R, int C, int K) {
    int row = R - 1, col = 0, d = 0;
    for (int i = 1; i < K; i++) {
        board[row][col] = i;
        row += dir[d].first;
        col += dir[d].second;
        if ((row < 0) || (row >= R) || (col < 0) || (col >= C) || board[row][col]) { //범위를 벗어나면
            row = row - dir[d].first + dir[(d + 1) % 4].first;
            col = col - dir[d].second + dir[(d + 1) % 4].second;
            d = (d + 1) % 4;
        }
    }
    return make_pair(col + 1, R - row);
}

int main() {
    int C, R, K;

    cin >> C >> R >> K;
    if (K > C * R) { //착석 불가
        cout << 0;
        return 0;
    }
    board.assign(R, vector<int>(C));
    pair<int, int> pos = findPos(R, C, K);
    cout << pos.first << ' ' << pos.second;
}