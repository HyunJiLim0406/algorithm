#include <iostream>
#include <queue>
#include <vector>

using namespace std;
typedef pair<int, int> pp;

int N;
vector<vector<int>> board;
pp dir[6] = {{-2, -1},
             {-2, 1},
             {0,  -2},
             {0,  2},
             {2,  -1},
             {2,  1}};

int bfs(pp start, pp end) {
    queue<pp> q;
    board[start.first][start.second] = 0;
    q.push(start);
    while (!q.empty()) {
        int row = q.front().first; //행
        int col = q.front().second; //열
        int dist = board[row][col]; //거리
        q.pop();

        if ((row == end.first) && (col == end.second)) //목표지점 도달
            return dist;
        for (int i = 0; i < 6; i++) {
            int nr = row + dir[i].first;
            int nc = col + dir[i].second;
            if ((nr >= 0) && (nr < N) && (nc >= 0) && (nc < N) && (board[nr][nc] == -1)) { //범위내에 있는 미방문 좌표
                board[nr][nc] = dist + 1;
                q.push(make_pair(nr, nc));
            }
        }
    }
    return -1; //목표지점 도달하지 못함
}

int main() {
    pp start, end;

    cin >> N >> start.first >> start.second >> end.first >> end.second;
    board.assign(N, vector<int>(N, -1));
    cout << bfs(start, end);
}