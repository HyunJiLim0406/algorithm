#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int N;
vector<vector<int>> board;
vector<vector<ll>> dp;

ll dfs(int row, int col) {
    if (dp[row][col] == -1) { //미방문 좌표
        dp[row][col] = 0; //방문 표시
        int jump = board[row][col];
        if (row + jump < N) //범위 확인
            dp[row][col] += dfs(row + jump, col);
        if (col + jump < N) //범위 확인
            dp[row][col] += dfs(row, col + jump);
    }
    return dp[row][col];
}

int main() {
    cin >> N;
    board.assign(N, vector<int>(N, 0));
    dp.assign(N, vector<ll>(N, -1));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cin >> board[i][j];
    }
    dp[N - 1][N - 1] = 1; //목표 지점 초기화
    cout << dfs(0, 0);
}