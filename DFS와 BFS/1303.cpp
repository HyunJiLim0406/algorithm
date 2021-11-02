#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> board;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int dfs(int m, int n, int row, int col, char ch) {
    int node = 1;
    board[row][col] = '.'; //방문처리
    for (int i = 0; i < 4; i++) {
        int nr = row + dr[i];
        int nc = col + dc[i];
        if (nr < 0 || nr >= m || nc < 0 || nc >= n || board[nr][nc] != ch) //범위 벗어나거나 이미 방문
            continue;
        node += dfs(m, n, nr, nc, ch);
    }
    return node;
}

int main() {
    int n, m;
    string input;
    vector<int> ans(2, 0);

    cin >> n >> m;
    board.assign(m, vector<char>(n));
    for (int i = 0; i < m; i++) {
        cin >> input;
        for (int j = 0; j < n; j++)
            board[i][j] = input[j];
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] != '.') {
                char ch = board[i][j];
                int num = dfs(m, n, i, j, ch); //모인 병사의 수
                if (ch == 'W')
                    ans[0] += (num * num);
                if (ch == 'B')
                    ans[1] += (num * num);
            }
        }
    }

    cout<<ans[0]<<' '<<ans[1];
}