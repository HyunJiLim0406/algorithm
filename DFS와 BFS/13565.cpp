#include <iostream>
#include <vector>

using namespace std;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
vector<vector<int>> board;

void dfs(int m, int n, int row, int col) {
    board[row][col] = 1; //방문 표시
    for (int i = 0; i < 4; i++) {
        int nr = row + dr[i];
        int nc = col + dc[i];
        if (nr < 0 || nr >= m || nc < 0 || nc >= n || board[nr][nc]) //범위 벗어나거나 벽
            continue;
        dfs(m, n, nr, nc);
    }
}

int main() {
    int m, n;
    string input;

    cin >> m >> n;
    board.assign(m + 2, vector<int>(n, 0)); //위아래 추가
    for (int i = 1; i <= m; i++) {
        cin >> input;
        for (int j = 0; j < n; j++)
            board[i][j] = input[j] - '0';
    }
    dfs(m + 2, n, 0, 0);
    cout << ((board[m + 1][0]) ? "YES" : "NO");
}