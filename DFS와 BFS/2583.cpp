#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int M, N;
vector<vector<int>> board;
pair<int, int> dir[4] = {{-1, 0},  //상
                         {1,  0},  //하
                         {0,  -1}, //좌
                         {0,  1}}; //우

void fillBoard(int s_row, int s_col, int e_row, int e_col) { //직사각형 채우기
    for (int i = s_row; i < e_row; i++) {
        for (int j = s_col; j < e_col; j++)
            board[i][j] = 1;
    }
}

int dfs(pair<int, int> cur) {
    int result = 1;
    int row = cur.first;
    int col = cur.second;
    board[row][col] = 1; //방문 처리
    for (int i = 0; i < 4; i++) {
        int nr = row + dir[i].first;
        int nc = col + dir[i].second;
        if ((nr >= 0) && (nr < M) && (nc >= 0) && (nc < N) && !board[nr][nc]) //미방문 빈 공간
            result += dfs(make_pair(nr, nc)); //result 갱신
    }
    return result;
}

int main() {
    int K, x1, y1, x2, y2;

    cin >> M >> N >> K;
    board.assign(M, vector<int>(N, 0));
    for (int i = 0; i < K; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        fillBoard(M - y2, x1, M - y1, x2);
    }

    int cnt = 0;
    vector<int> arr;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 0) {
                cnt++;
                arr.push_back(dfs(make_pair(i, j)));
            }
        }
    }
    sort(arr.begin(), arr.end());
    cout << cnt << '\n';
    for (int i = 0; i < cnt; i++)
        cout << arr[i] << ' ';
}