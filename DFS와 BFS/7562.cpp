#include <iostream>
#include <cstring>
#include <queue>
#include <utility>

using namespace std;

int matrix[300][300], l;
pair<int, int> dir[8] = {{1,  -2}, //나이트가 갈 수 있는 방향
                         {2,  -1},
                         {2,  1},
                         {1,  2},
                         {-1, 2},
                         {-2, 1},
                         {-2, -1},
                         {-1, -2}};

int bfs(pair<int, int> start, pair<int, int> end) {
    queue<pair<int, int>> q;

    q.push(start);
    while (matrix[end.first][end.second] == 0) { //도착점 도달하면 반복 종료
        int col = q.front().first;
        int row = q.front().second;
        q.pop();
        for (int i = 0; i < 8; i++) { //방향 체크
            int next_col = col + dir[i].first;
            int next_row = row + dir[i].second;
            if ((next_col >= 0) && (next_col < l) && (next_row >= 0) && (next_row < l) && //범위 체크
                (matrix[next_col][next_row] == 0)) { //방문 체크
                matrix[next_col][next_row] = matrix[col][row] + 1; //matrix[next_col][next_row]를 오기 위해 몇 번 거쳐야 하는가?
                q.push(make_pair(next_col, next_row));
            }
        }
    }
    return matrix[end.first][end.second] - 1;
}

int main() {
    int T, w, x, y, z;

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> l >> w >> x >> y >> z;
        matrix[w][x] = 1;
        pair<int, int> start = {w, x};
        pair<int, int> end = {y, z};
        cout << bfs(start, end) << '\n';
        for (int i = 0; i < l; i++) //2차원 배열 초기화
            memset(matrix[i], 0, sizeof(int) * l);
    }
}