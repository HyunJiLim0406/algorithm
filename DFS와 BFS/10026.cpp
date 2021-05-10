#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

int N;
vector<vector<char>> board;
vector<vector<bool>> visited;
pair<int, int> dir[4] = {{-1, 0},  //상
                         {1,  0},  //하
                         {0,  -1}, //좌
                         {0,  1}}; //우

void dfs(pair<int, int> cur, bool isColorWeakness) {
    int row = cur.first;
    int col = cur.second;
    char c = board[row][col];

    visited[row][col] = true; //방문 처리
    for (int i = 0; i < 4; i++) {
        int nr = row + dir[i].first;
        int nc = col + dir[i].second;
        if ((nr >= 0) && (nr < N) && (nc >= 0) && (nc < N) && (!visited[nr][nc])) { //범위 내에 있는 미방문 좌표
            if (board[nr][nc] == c) //색이 같을 때
                dfs(make_pair(nr, nc), isColorWeakness);
            else if (isColorWeakness && (c != 'B') && (board[nr][nc] != 'B')) //색약이며 두 좌표가 각각 R 또는 G일 때
                dfs(make_pair(nr, nc), isColorWeakness);
        }
    }
}

int main() {
    string input;
    int r1 = 0, r2 = 0;

    cin >> N;
    board.assign(N, vector<char>(N));
    for (int i = 0; i < N; i++) {
        cin >> input;
        for (int j = 0; j < N; j++)
            board[i][j] = input[j];
    }

    visited.assign(N, vector<bool>(N, false)); //색약이 아닌 경우
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                r1++;
                dfs(make_pair(i, j), false);
            }
        }
    }

    visited.assign(N, vector<bool>(N, false)); //색약인 경우
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                r2++;
                dfs(make_pair(i, j), true);
            }
        }
    }
    cout << r1 << ' ' << r2;
}