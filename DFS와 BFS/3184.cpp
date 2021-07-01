#include <iostream>
#include <vector>
#include <string>

using namespace std;
typedef pair<int, int> pp;

int R, C;
vector<vector<char>> board;
pp dir[4] = {{-1, 0},  //상
             {1,  0},  //하
             {0,  -1}, //좌
             {0,  1}}; //우

pp dfs(int r, int c) {
    int s = 0, w = 0;
    if (board[r][c] == 'o') //양
        s++;
    if (board[r][c] == 'v') //늑대
        w++;
    board[r][c] = '#';
    for (int i = 0; i < 4; i++) {
        int nr = r + dir[i].first;
        int nc = c + dir[i].second;
        if ((nr >= 0) && (nr < R) && (nc >= 0) && (nc < C) && (board[nr][nc] != '#')) { //범위내에 있는 미방문 정점
            pp result = dfs(nr, nc);
            s += result.first; //양
            w += result.second; //늑대
        }
    }
    return make_pair(s, w);
}

int main() {
    int sheep = 0, wolf = 0;
    string input;

    cin >> R >> C;
    board.assign(R, vector<char>(C));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'o') //양의 수
                sheep++;
            if (board[i][j] == 'v') //늑대의 수
                wolf++;
        }
    }
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (board[i][j] != '#') { //미방문 영역에 대해 dfs 호출
                pp result = dfs(i, j);
                if (result.first > result.second) //해당 영역에 양이 더 많다면
                    wolf -= result.second;
                else //해당 영역에 늑대가 더 많다면(같거나)
                    sheep -= result.first;
            }
        }
    }
    cout << sheep << ' ' << wolf;
}