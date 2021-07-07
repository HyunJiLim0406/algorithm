#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> color_ans(2); //색깔별 최대 배치 수
vector<bool> up_left, up_right; //좌상->우하, 우상->좌하
vector<vector<int>> board;

void backtracking(int row, int col, int color, int num) {
    if (col >= N) { //범위 조절
        row++;
        col = (col % 2 == 0) ? 1 : 0;
    }
    if (row == N) { //끝까지 도달
        color_ans[color] = max(color_ans[color], num);
        return;
    }
    int ul = col - row + N - 1, ur = col + row; //양 대각선에서의 인덱스
    if (board[row][col] && !up_left[ul] && !up_right[ur]) { //배치 가능하면
        up_left[ul] = up_right[ur] = true; //배치 처리
        backtracking(row, col + 2, color, num + 1);
        up_left[ul] = up_right[ur] = false; //배치 취소
    }
    backtracking(row, col + 2, color, num); //배치 하지 않음
}

int main() {
    cin >> N;
    board.assign(N, vector<int>(N));
    up_left.assign(2 * N - 1, false);
    up_right.assign(2 * N - 1, false);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cin >> board[i][j];
    }

    backtracking(0, 0, 0, 0); //검은색 칸
    backtracking(0, 1, 1, 0); //흰색 칸
    cout << color_ans[0] + color_ans[1];
}