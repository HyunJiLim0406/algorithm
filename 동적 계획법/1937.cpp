#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> pp;

int n;
vector<vector<int>> board, dp;
pp dir[4] = {{-1, 0},  //상
             {1,  0},  //하
             {0,  -1}, //좌
             {0,  1}}; //우

int dfs(int r, int c) {
    if (!dp[r][c]) { //dp 갱신 전
        dp[r][c] = 1; //초기화
        for (int i = 0; i < 4; i++) {
            int nr = r + dir[i].first;
            int nc = c + dir[i].second;
            if ((nr >= 0) && (nr < n) && (nc >= 0) && (nc < n) && (board[nr][nc] > board[r][c])) //방문 가능
                dp[r][c] = max(dp[r][c], dfs(nr, nc) + 1); //갱신
        }
    }
    return dp[r][c];
}

int main() {
    cin >> n;
    board.assign(n, vector<int>(n, 0));
    dp.assign(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> board[i][j];
    }
    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            result = max(result, dfs(i, j)); //(i, j)에서 먹기 시작하면 며칠을 살 수 있나?
    }
    cout << result;
}