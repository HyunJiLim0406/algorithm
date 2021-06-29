#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<bool>> board;
pair<int, int> dir[4] = {{-1, 0},  //상
                         {1,  0},  //하
                         {0,  -1}, //좌
                         {0,  1}}; //우

int dfs(int r, int c) {
    int num = 1;
    board[r][c] = false; //방문 처리
    for (int i = 0; i < 4; i++) {
        int nr = r + dir[i].first;
        int nc = c + dir[i].second;
        if ((nr >= 0) && (nr < n) && (nc >= 0) && (nc < m) && board[nr][nc]) //범위내에 있는 미방문 정점
            num += dfs(nr, nc);
    }
    return num;
}

int main() {
    int result = 0, cnt = 0, input;

    cin >> n >> m;
    board.assign(n, vector<bool>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> input;
            board[i][j] = input;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j]) {
                cnt++; //dfs 실행 횟수
                result = max(result, dfs(i, j)); //그림 넓이 최댓값 갱신
            }
        }
    }
    cout << cnt << '\n' << result;
}