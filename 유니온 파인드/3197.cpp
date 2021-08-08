#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int R, C;
vector<vector<char>> board;
vector<vector<bool>> visited;
pair<int, int> dir[4] = {{-1, 0},
                         {1,  0},
                         {0,  -1},
                         {0,  1}};

int main() {
    string input;
    vector<pair<int, int>> swans;
    queue<pair<int, int>> water, swan;

    cin >> R >> C;
    board.assign(R, vector<char>(C));
    visited.assign(R, vector<bool>(C, false));
    for (int i = 0; i < R; i++) {
        cin >> input;
        for (int j = 0; j < C; j++) {
            board[i][j] = input[j];
            if (board[i][j] != 'X') //빙하가 아님
                water.emplace(i, j);
            if (board[i][j] == 'L') //백조
                swans.emplace_back(i, j);
        }
    }

    int day = 1;
    visited[swans[0].first][swans[0].second] = true;
    swan.emplace(swans[0].first, swans[0].second);
    while (true) {
        int size = water.size();
        while (size--) { //빙하 녹이기
            int row = water.front().first;
            int col = water.front().second;
            water.pop();

            for (int i = 0; i < 4; i++) {
                int nr = row + dir[i].first;
                int nc = col + dir[i].second;
                if (nr >= 0 && nr < R && nc >= 0 && nc < C && board[nr][nc] == 'X') { //범위 내에 있고 물에 닿은 빙하라면
                    water.emplace(nr, nc);
                    board[nr][nc] = '.';
                }
            }
        }

        queue<pair<int, int>> next;
        while (!swan.empty()) {
            int row = swan.front().first;
            int col = swan.front().second;
            swan.pop();

            for (int i = 0; i < 4; i++) {
                int nr = row + dir[i].first;
                int nc = col + dir[i].second;
                if (nr < 0 || nr >= R || nc < 0 || nc >= C || visited[nr][nc]) //방문한 곳이거나 범위를 벗어남
                    continue;
                visited[nr][nc] = true; //방문 처리
                if (nr == swans[1].first && nc == swans[1].second) { //다른 백조와 만남
                    cout << day;
                    return 0;
                } else if (board[nr][nc] == 'X') //빙하라면 다음번에 진입 가능
                    next.emplace(nr, nc);
                else //물이라면 지금 진입 가능
                    swan.emplace(nr, nc);
            }
        }
        swan = next; //다음번에 이동하게될 곳
        day++;
    }
}