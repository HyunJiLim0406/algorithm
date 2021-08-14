#include <iostream>
#include <vector>

using namespace std;

bool is_cycled = false;
int N, M;
vector<vector<int>> board, dp;
pair<int, int> dir[4] = {{-1, 0},  //상
                         {1,  0},  //하
                         {0,  -1}, //좌
                         {0,  1}}; //우

int dfs(int row, int col) {
    if (is_cycled) //순환에 빠짐
        return -1;
    if (row < 0 || row >= N || col < 0 || col >= M || !board[row][col]) //범위 벗어나거나 구멍에 빠짐
        return 0;
    if (dp[row][col] == -1) { //아직 답을 구하고 있는 좌표인데 접근했다면 순환에 빠진 것
        is_cycled = true;
        return -1;
    }
    if (dp[row][col] == 0) { //한번도 접근한 적 없는 좌표
        dp[row][col] = -1; //접근 표시
        int result = 0;
        for (int i = 0; i < 4; i++) { //4방향 중 가장 많이 움직일 수 있는 방향 찾기
            int nr = row + board[row][col] * dir[i].first;
            int nc = col + board[row][col] * dir[i].second;
            result = max(result, dfs(nr, nc));
        }
        dp[row][col] = result + 1; //갱신
    }
    return dp[row][col];
}

int main() {
    string input;

    cin >> N >> M;
    board.assign(N, vector<int>(M, 0));
    dp.assign(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++) {
        cin >> input;
        for (int j = 0; j < M; j++) {
            if (input[j] == 'H')
                continue;
            board[i][j] = input[j] - '0';
        }
    }
    int result = dfs(0, 0);
    if (is_cycled)
        cout << -1;
    else
        cout << result;
}