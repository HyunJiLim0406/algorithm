#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> pii;

vector<vector<int>> board;
pii dir[4] = {{-1, 0},  //상
              {1,  0},  //하
              {0,  -1}, //좌
              {0,  1}}; //우

int bfs(vector<vector<pii>> &virus, int n, int s, int x, int y) {
    queue<pii> q;
    for (int i = 1; i < virus.size(); i++) { //바이러스 번호순으로 투입
        for (int j = 0; j < virus[i].size(); j++)
            q.push(virus[i][j]);
    }
    while (s--) { //시간
        int size = q.size(); //큐의 크기
        while (size--) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = row + dir[i].first;
                int nc = col + dir[i].second;
                if (nr < 0 || nr >= n || nc < 0 || nc >= n || board[nr][nc]) //범위를 벗어나거나 이미 다른 바이러스가 있으면
                    continue;
                board[nr][nc] = board[row][col]; //바이러스 전염
                q.push(pii(nr, nc)); //큐에 삽입
            }
        }
    }
    return board[x][y]; //바이러스 종류 반환
}

int main() {
    int n, k, s, x, y;

    cin >> n >> k;
    board.assign(n, vector<int>(n, 0));
    vector<vector<pii>> virus(k + 1, vector<pii>(0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j]) //바이러스가 존재하면
                virus[board[i][j]].emplace_back(i, j);
        }
    }
    cin >> s >> x >> y;
    cout << bfs(virus, n, s, x - 1, y - 1);
}