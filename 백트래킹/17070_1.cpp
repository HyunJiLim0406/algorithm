#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int tot_cnt, N;
vector<vector<int>> map;
pair<int, int> dir[4] = {{0, 0},
                         {1, 0},
                         {0, 1},
                         {1, 1}};

void backtracking(pair<int, int> pos, int status) { //갈 수 있는 모든 방향으로 가보는 백트래킹
    if ((pos.first == N) && (pos.second == N)) { //(N, N)에 도착하면 tot_cnt 늘려주고 리턴
        tot_cnt++;
        return;
    }
    bool reachable[4]; //각 좌표에 대해 갈 수 있는지
    for (int i = 0; i < 4; i++) {
        int nr = pos.first + dir[i].first;
        int nc = pos.second + dir[i].second;
        if ((nr >= 0) && (nr <= N) && (nc >= 0) && (nc <= N) && (map[nr][nc] == 0)) //범위 내에 있고 벽이 아니면
            reachable[i] = true;
        else
            reachable[i] = false;
    }
    bool isDiagonal = true;
    for (int i = 0; i < 4; i++) {
        if (!reachable[i]) {
            isDiagonal = false;
            break;
        }
    }
    if (isDiagonal) //대각선으로 이동 가능한지
        backtracking(make_pair(pos.first + 1, pos.second + 1), 2);
    if ((status != 1) && reachable[0] && reachable[2]) //가로로 이동 가능한지
        backtracking(make_pair(pos.first, pos.second + 1), 0);
    if ((status != 0) && reachable[0] && reachable[1]) //세로로 이동 가능한지
        backtracking(make_pair(pos.first + 1, pos.second), 1);
}

int main() {
    cin >> N;
    map.assign(N + 1, vector<int>(N + 1, 1));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++)
            cin >> map[i][j];
    }
    backtracking(make_pair(1, 2), 0); //맨 처음은 가로로
    cout << tot_cnt;
}