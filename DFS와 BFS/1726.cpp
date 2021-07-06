#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct info {
    int r, c, d;
};

int M, N;
vector<vector<int>> board;
vector<vector<vector<int>>> dist;
pair<int, int> direction[4] = {{0,  1},  //동
                               {1,  0},  //남
                               {0,  -1}, //서
                               {-1, 0}}; //북

int bfs(vector<info> init) {
    queue<info> q;
    dist[init[0].r][init[0].c][init[0].d] = 1; //시작점 초기화
    q.push(init[0]);
    while (!q.empty()) {
        int row = q.front().r; //행
        int col = q.front().c; //열
        int dir = q.front().d; //방향
        int distance = dist[row][col][dir]; //거리
        q.pop();

        if (row == init[1].r && col == init[1].c && dir == init[1].d) //목표 도달
            return distance - 1;
        for (int i = 0; i < 4; i++) { //방향 바꾸기
            if ((i % 2 == 1) && !dist[row][col][(dir + i) % 4]) { //해당 정점에서 해당 방향으로 있어본 적 없다면
                dist[row][col][(dir + i) % 4] = distance + 1;
                q.push({row, col, (dir + i) % 4});
            }
        }
        for (int i = 1; i <= 3; i++) { //이동
            row += direction[dir].first;
            col += direction[dir].second;
            if ((row < 0) || (row >= M) || (col < 0) || (col >= N) || board[row][col]) //범위를 벗어나거나 궤도가 없다면
                break;
            if (!dist[row][col][dir]) { //해당 정점에서 해당 방향으로 있어본 적 없다면
                dist[row][col][dir] = distance + 1;
                q.push({row, col, dir});
            }
        }
    }
    return -1;
}

int main() {
    int r, c, d;
    vector<info> init(2);

    cin >> M >> N;
    board.assign(M, vector<int>(N));
    dist.assign(M, vector<vector<int>>(N, vector<int>(4)));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++)
            cin >> board[i][j];
    }
    for (int i = 0; i < 2; i++) {
        cin >> r >> c >> d;
        if (d == 2) //서쪽인 경우
            d = 3;
        else if (d == 3) //남쪽인 경우
            d = 2;
        init[i] = {r - 1, c - 1, d - 1};
    }
    cout << bfs(init);
}