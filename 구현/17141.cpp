#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
const int INF = 1e9;

int n;
vector<vector<int>> board;
vector<pii> pos;
pii dir[4] = {{-1, 0},  //상
              {1,  0},  //하
              {0,  -1}, //좌
              {0,  1}}; //우

int infected(vector<vector<int>> &visited) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j] && board[i][j] != 1) //전부 감염되지 않음
                return INF;
            if (visited[i][j]) //걸리는 시간 갱신
                ans = max(ans, visited[i][j]);
        }
    }
    return ans - 1;
}

int bfs(vector<pii> init) {
    vector<vector<int>> visited(n, vector<int>(n, 0));
    queue<pii> q;
    for (int i = 0; i < init.size(); i++) { //초기 입력
        visited[init[i].first][init[i].second] = 1;
        q.push(init[i]);
    }
    while (!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        int dist = visited[row][col];
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = row + dir[i].first;
            int nc = col + dir[i].second;
            if (nr < 0 || nr >= n || nc < 0 || nc >= n || visited[nr][nc] || board[nr][nc] == 1) //범위 벗어나거나 방문했거나 벽
                continue;
            visited[nr][nc] = dist + 1;
            q.push(make_pair(nr, nc));
        }
    }
    return infected(visited);
}

int main() {
    int m;

    cin >> n >> m;
    board.assign(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 2) //바이러스를 놓을 수 있는 위치
                pos.emplace_back(i, j);
        }
    }
    vector<int> comb(pos.size(), 0); //조합용 배열
    for (int i = 0; i < m; i++)
        comb[i] = 1;

    int ans = INF;
    do {
        vector<pii> init;
        for (int i = 0; i < comb.size(); i++) {
            if (comb[i]) //바이러스 위치
                init.push_back(pos[i]);
        }
        ans = min(ans, bfs(init));
    } while (prev_permutation(comb.begin(), comb.end()));
    cout << ((ans == INF) ? -1 : ans);
}