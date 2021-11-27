#include <iostream>
#include <vector>

using namespace std;

vector<string> board;
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

pair<int, int> dfs(int r, int c, int row, int col) {
    int v = 0, k = 0;
    if (board[row][col] == 'v') //늑대
        v++;
    if (board[row][col] == 'k') //양
        k++;
    board[row][col] = '#'; //방문 처리
    for (int i = 0; i < 4; i++) {
        int nr = row + dr[i];
        int nc = col + dc[i];
        if (nr < 0 || nr >= r || nc < 0 || nc >= c || board[nr][nc] == '#') //범위 벗어나거나 울타리
            continue;
        pair<int, int> ans = dfs(r, c, nr, nc);
        v += ans.first;
        k += ans.second;
    }
    return {v, k};
}

int main() {
    int r, c;

    cin >> r >> c;
    board.assign(r, "");
    for (int i = 0; i < r; i++)
        cin >> board[i];

    int v = 0, k = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (board[i][j] == '#')
                continue;
            pair<int, int> ans = dfs(r, c, i, j);
            if (ans.first >= ans.second) //늑대가 양보다 많거나 같음
                v += ans.first;
            else //양이 더 많음
                k += ans.second;
        }
    }
    cout << k << ' ' << v;
}