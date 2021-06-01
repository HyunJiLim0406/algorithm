#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pp;

vector<vector<int>> board;
vector<vector<bool>> visited;
pp dir[4] = {{-1, 0},  //상
             {1,  0},  //하
             {0,  -1}, //좌
             {0,  1}}; //우

void rain(int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            board[i][j] = max(0, board[i][j] - 1); //0보다 작아지지 않도록
    }
}

void dfs(pp cur, int size) {
    visited[cur.first][cur.second] = true;
    for (int i = 0; i < 4; i++) {
        int nr = cur.first + dir[i].first;
        int nc = cur.second + dir[i].second;
        if ((nr >= 0) && (nr < size) && (nc >= 0) && (nc < size) && !visited[nr][nc] && board[nr][nc])
            dfs(make_pair(nr, nc), size);
    }
}

int findSector(int size) {
    int cnt = 0; //구역의 수
    visited.assign(size, vector<bool>(size, false)); //방문 체크
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (!visited[i][j] && board[i][j]) { //방문하지 않았고 물에 잠기지 않았다면 dfs
                cnt++;
                dfs(make_pair(i, j), size);
            }
        }
    }
    return cnt;
}

int main() {
    int N, max_height = 0, max_sector = 1;

    cin >> N;
    board.assign(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            max_height = max(max_height, board[i][j]); //최대 높이
        }
    }
    for (int i = 1; i < max_height; i++) { //1~(최대 높이-1), 0 : 구역 1개 / 최대 높이 : 구역 0개
        rain(N); //비가 내림
        max_sector = max(max_sector, findSector(N)); //구역 계산하고 갱신
    }
    cout << max_sector;
}