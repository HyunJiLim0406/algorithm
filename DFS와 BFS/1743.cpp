#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<bool>> board;
pair<int, int> dir[4] = {{-1, 0},  //상
                         {1,  0},  //하
                         {0,  -1}, //좌
                         {0,  1}}; //우

int dfs(int r, int c) {
    int cnt = 1;
    board[r][c] = false; //방문처리
    for (int i = 0; i < 4; i++) {
        int nr = r + dir[i].first;
        int nc = c + dir[i].second;
        if ((nr >= 0) && (nr < N) && (nc >= 0) && (nc < M) && board[nr][nc]) //범위내에 있는 미방문 정점
            cnt += dfs(nr, nc);
    }
    return cnt;
}

int main() {
    int K, r, c, result = 0;

    cin >> N >> M >> K;
    board.assign(N, vector<bool>(M));
    while (K--) {
        cin >> r >> c;
        board[r - 1][c - 1] = true;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j])
                result = max(result, dfs(i, j)); //가장 큰 음식물 크기 갱신
        }
    }
    cout << result;
}