#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> pp;

vector<vector<int>> board, dp;
pp dir[4] = {{-1, 0},  //상
             {1,  0},  //하
             {0,  -1}, //좌
             {0,  1}}; //우

int dpDfs(pp cur, int M, int N) {
    int row = cur.first;
    int col = cur.second;
    if (row == (M - 1) && col == (N - 1)) //목표 지점
        return 1;
    if (dp[row][col] != -1) //이미 방문한 지점
        return dp[row][col];
    dp[row][col] = 0; //방문 처리

    for (int i = 0; i < 4; i++) {
        int nr = row + dir[i].first;
        int nc = col + dir[i].second;

        if ((nr < 0) || (nr >= M) || (nc < 0) || (nc >= N)) //범위 체크
            continue;
        if (board[row][col] > board[nr][nc]) //내려갈 수 있으면
            dp[row][col] += dpDfs(make_pair(nr, nc), M, N); //dfs로 파고들고 갚 갱신
    }
    return dp[row][col];
}

int main() {
    int M, N;

    cin >> M >> N;
    board.assign(M, vector<int>(N, 0));
    dp.assign(M, vector<int>(N, -1));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++)
            cin >> board[i][j];
    }
    cout << dpDfs(make_pair(0, 0), M, N);
}