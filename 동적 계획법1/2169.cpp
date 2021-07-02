#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> board, dp;

int fillDp() {
    dp[0][0] = board[0][0];
    for (int i = 1; i < M; i++) //맨 윗줄 초기화
        dp[0][i] = dp[0][i - 1] + board[0][i];
    for (int i = 1; i < N; i++) { //각 행에 대해
        vector<int> left(M), right(M); //각 열에 대해 왼쪽에서 오는 경우, 오른쪽에서 오는 경우
        left[0] = dp[i - 1][0] + board[i][0]; //0열은 위에서만 올 수 있음
        right[M - 1] = dp[i - 1][M - 1] + board[i][M - 1]; //M-1열은 위에서만 올 수 있음
        for (int j = 1; j < M; j++) //왼쪽에서 오거나, 위에서 오거나
            left[j] = max(dp[i - 1][j], left[j - 1]) + board[i][j];
        for (int j = M - 2; j >= 0; j--) //오른쪽에서 오거나, 위에서 오거나
            right[j] = max(dp[i - 1][j], right[j + 1]) + board[i][j];
        for (int j = 0; j < M; j++) //최댓값
            dp[i][j] = max(left[j], right[j]);
    }
    return dp[N - 1][M - 1];
}

int main() {
    cin >> N >> M;
    board.assign(N, vector<int>(M));
    dp.assign(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            cin >> board[i][j];
    }
    cout<<fillDp();
}