#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(int n, int m, int row, int col, vector<vector<int>> &board) {
    int dr[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
    int dc[8] = {0, 0, -1, 1, -1, 1, -1, 1};
    vector<vector<int>> visited(n, vector<int>(m, 0));
    queue<pair<int, int>> q;

    visited[row][col] = 1;
    q.push({row, col});
    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        int d = visited[r][c];
        q.pop();

        if (board[r][c]) //가장 가까운 상어
            return d - 1;
        for (int i = 0; i < 8; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr < 0 || nr >= n || nc < 0 || nc >= m || visited[nr][nc])
                continue;
            visited[nr][nc] = d + 1;
            q.push({nr, nc});
        }
    }
    return -1;
}

int main() {
    int n, m;

    cin >> n >> m;
    vector<vector<int>> board(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> board[i][j];
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            ans = max(ans, bfs(n, m, i, j, board)); //모든 좌표에 대해 bfs
    }
    cout << ans;
}