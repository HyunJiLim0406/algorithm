#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;
const int INF = 1e9;
pair<int, int> direction[4] = {{-1, 0},  //상
                               {1,  0},  //하
                               {0,  -1}, //좌
                               {0,  1}}; //우

vector<vector<int>> dist;
struct status { //행, 열, 방향, 비용
    int r, c, d, m;
};

int bfs(vector<vector<int>> board) {
    int size = board.size();
    queue<status> q;
    dist[0][0] = 0; //시작점
    q.push({0, 0, 3, 0}); //시작점의 오른쪽
    q.push({0, 0, 1, 0}); //시작점의 왼쪽

    while (!q.empty()) {
        int row = q.front().r;
        int col = q.front().c;
        int dir = q.front().d;
        int cost = q.front().m;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = row + direction[i].first;
            int nc = col + direction[i].second;
            if ((nr >= 0) && (nr < size) && (nc >= 0) && (nc < size) && (board[nr][nc] == 0)) { //범위 내에 있고, 길이라면
                if ((i == dir) && ((cost + 100) <= dist[nr][nc])) { //같은 방향 진행이면 +100하여 비교. 같은 지점을 다른 방향에서 올 수 있기 때문에 <=
                    dist[nr][nc] = cost + 100;
                    q.push({nr, nc, dir, cost + 100});
                } else if ((i != dir) && ((cost + 600) <= dist[nr][nc])) { //다른 방향 진행이면 +600하여 비교. 같은 지점을 다른 방향에서 올 수 있기 때문에 <=
                    dist[nr][nc] = cost + 600;
                    q.push({nr, nc, i, cost + 600});
                }
            }
        }
    }
    return dist[size - 1][size - 1];
}

int solution(vector<vector<int>> board) {
    dist.assign(board.size(), vector<int>(board.size(), INF)); //거리 배열 초기화
    int answer = bfs(board);
    return answer;
}

int main() {
    cout << solution({{0, 0, 0},
                      {0, 0, 0},
                      {0, 0, 0}}) << '\n';
    cout << solution({{0, 0, 0, 0, 0, 0, 0, 1},
                      {0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 1, 0, 0},
                      {0, 0, 0, 0, 1, 0, 0, 0},
                      {0, 0, 0, 1, 0, 0, 0, 1},
                      {0, 0, 1, 0, 0, 0, 1, 0},
                      {0, 1, 0, 0, 0, 1, 0, 0},
                      {1, 0, 0, 0, 0, 0, 0, 0}}) << '\n';
    cout << solution({{0, 0, 1, 0},
                      {0, 0, 0, 0},
                      {0, 1, 0, 1},
                      {1, 0, 0, 0}}) << '\n';
    cout << solution({{0, 0, 0, 0, 0, 0},
                      {0, 1, 1, 1, 1, 0},
                      {0, 0, 1, 0, 0, 0},
                      {1, 0, 0, 1, 0, 1},
                      {0, 1, 0, 0, 0, 1},
                      {0, 0, 0, 0, 0, 0}}) << '\n';
}