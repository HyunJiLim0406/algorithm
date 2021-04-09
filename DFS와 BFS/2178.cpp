#include <iostream>
#include <string>
#include <queue>
#include <utility>

using namespace std;

//범위 초과 때문에 상하좌우 한줄씩 추가
int matrix[102][102], N, M;
pair<int, int> dir[4] = {{-1, 0},  //상
                         {1, 0},  //하
                         {0, -1}, //좌
                         {0, 1}}; //우

void bfs(pair<int, int> start) { //큐로 구현
    queue<pair<int, int>> q;

    q.push(start);
    while (!q.empty()) { //큐에 들어있는 모든 원소에 대해 가능한 방향 체크
        int col = q.front().first;
        int row = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) { //상하좌우 체크
            int next_col = col + dir[i].first;
            int next_row = row + dir[i].second;
            if (matrix[next_col][next_row] == 1) {
                matrix[next_col][next_row] = matrix[col][row] + 1; //matrix[next_col][next_row]를 오기 위해 몇 번 거쳐야 하는가?
                q.push(make_pair(next_col, next_row));
            }
        }
    }
}

int main() {
    string tmp;

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> tmp;
        for (int j = 1; j <= M; j++)
            matrix[i][j] = tmp[j - 1] - '0';
    }
    pair<int, int> start = {1, 1};
    bfs(start);
    cout << matrix[N][M];
}