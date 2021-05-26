#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
const int INF = 1e9;
typedef pair<int, int> pp;

struct status { //행, 열, 거울 개수, 방향
    int r, c, m, d;
};
int W, H, min_mirror = INF;
vector<vector<char>> board;
vector<vector<int>> visited;
pp dir[4] = {{-1, 0},  //상
             {1,  0},  //하
             {0,  -1}, //좌
             {0,  1}}; //우

int bfs(pp start) {
    queue<status> q;
    visited[start.first][start.second] = 0;
    for (int i = 0; i < 4; i++) //시작점은 상하좌우 모든 방향 가능
        q.push({start.first, start.second, 0, i});
    while (!q.empty()) {
        int row = q.front().r;
        int col = q.front().c;
        int mirror = q.front().m;
        int direction = q.front().d;
        q.pop();

        if (board[row][col] == 'C') //도착점이면 최솟값 갱신
            min_mirror = min(min_mirror, mirror);
        for (int i = 0; i < 4; i++) {
            if (((i / 2) == (direction / 2)) && (i != direction)) //반대 방향은 갈 수 없음
                continue;
            int nr = row + dir[i].first;
            int nc = col + dir[i].second;
            int nm = (i == direction) ? mirror : (mirror + 1); //같은 방향이라면 거울 설치 안해도 됨
            if ((nr >= 0) && (nr < H) && (nc >= 0) && (nc < W) && (board[nr][nc] != '*') && (visited[nr][nc] >= nm)) { //범위 내에 있고, 벽이 아니며, 최소 거울 개수를 갱신할 수 있으면
                visited[nr][nc] = nm; //최소 거울 개수 갱신
                q.push({nr, nc, nm, i});
            }
        }
    }
    return min_mirror;
}

int main() {
    string input;
    pp start;
    bool is_found = false;

    cin >> W >> H;
    board.assign(H, vector<char>(W));
    visited.assign(H, vector<int>(W, INF));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> board[i][j];
            if (!is_found && (board[i][j] == 'C')) { //시작점
                is_found = true;
                start = make_pair(i, j);
                board[i][j] = 'S';
            }
        }
    }
    cout << bfs(start);
}