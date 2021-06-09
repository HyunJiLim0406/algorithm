#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;
typedef pair<int, int> pp;

int N, M, max_dist;
vector<vector<char>> board;
vector<vector<int>> dist;
pp dir[4] = {{-1, 0},  //상
             {1,  0},  //하
             {0,  -1}, //좌
             {0,  1}}; //우

void bfs(pp start) {
    queue<pp> q;
    dist[start.first][start.second] = 0; //시작점 초기화
    q.push(start);
    while (!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        max_dist = max(max_dist, dist[row][col]); //최대 거리 갱신
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = row + dir[i].first;
            int nc = col + dir[i].second;
            if ((nr < 0) || (nr >= N) || (nc < 0) || (nc >= M)) //범위 벗어남
                continue;
            if (board[nr][nc] == 'L' && dist[nr][nc] == -1) { //미방문 땅
                dist[nr][nc] = dist[row][col] + 1;
                q.push(make_pair(nr, nc));
            }
        }
    }
}

int main() {
    string input;

    cin >> N >> M;
    board.assign(N, vector<char>(M));
    for (int i = 0; i < N; i++) {
        cin >> input;
        for (int j = 0; j < M; j++)
            board[i][j] = input[j];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j]=='L') {
                dist.assign(N, vector<int>(M, -1)); //거리 초기화
                bfs(make_pair(i, j));
            }
        }
    }
    cout << max_dist;
}