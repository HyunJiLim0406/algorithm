#include <iostream>
#include <vector>

using namespace std;

vector<vector<bool>> board;

int cntWater(int idx, int W) {
    bool is_blocked = false;
    int result = 0, tmp = 0;
    for (int i = 0; i < W; i++) {
        if (board[idx][i]) { //벽이라면 지금까지 고인 물 더해주기
            result += tmp;
            tmp = 0;
            is_blocked = true;
        } else if (is_blocked) //이전에 벽이 있었다면 고인 물 입력
            tmp++;
    }
    return result;
}

int main() {
    int H, W, input;

    cin >> H >> W;
    board.assign(H, vector<bool>(W, false));
    for (int i = 0; i < W; i++) {
        cin >> input;
        for (int j = 0; j < input; j++) //벽 설치
            board[H - j - 1][i] = true;
    }
    int result = 0;
    for (int i = 0; i < H; i++) //각 행마다 고이는 물 계산
        result += cntWater(i, W);
    cout << result;
}