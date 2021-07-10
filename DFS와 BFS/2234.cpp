#include <iostream>
#include <vector>
#include <set>

using namespace std;

int m, n;
vector<int> room_size;
vector<vector<int>> board, visited;
pair<int, int> dir[4] = {{0,  -1}, //서
                         {-1, 0},  //북
                         {0,  1},  //동
                         {1,  0}}; //남

int dfs(int row, int col, int idx) {
    int node = 1; //방의 넓이
    visited[row][col] = idx; //방문 처리
    for (int i = 0; i < 4; i++) {
        if (board[row][col] & (1 << i)) //벽이 있음
            continue;
        int nr = row + dir[i].first;
        int nc = col + dir[i].second;
        if (!visited[nr][nc]) //미방문 정점일 때
            node += dfs(nr, nc, idx);
    }
    return node;
}

int crushWall() {
    set<int, greater<>> s;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int cur_idx = visited[i][j]; //현재 위치의 인덱스
            for (int k = 0; k < 4; k++) {
                int r = i + dir[k].first;
                int c = j + dir[k].second;
                if ((r >= 0) && (r < m) && (c >= 0) && (c < n) && visited[r][c] != cur_idx) //다른 방이라면
                    s.insert(room_size[cur_idx] + room_size[visited[r][c]]); //벽 허문 결과 넣기
            }
        }
    }
    return *s.begin(); //가장 큰 값
}

int main() {
    int idx = 1, max_size = 0;

    cin >> n >> m;
    board.assign(m, vector<int>(n));
    visited.assign(m, vector<int>(n));
    room_size.push_back(-1); //더미
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cin >> board[i][j];
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) { //미방문 정점
                room_size.push_back(dfs(i, j, idx)); //방의 크기 입력
                max_size = max(max_size, room_size[idx++]); //최댓값 갱신
            }
        }
    }
    cout << idx - 1 << '\n' << max_size << '\n' << crushWall();
}