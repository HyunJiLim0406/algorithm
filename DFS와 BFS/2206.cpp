#include <iostream>
#include <string>
#include <queue>
#include <utility>

using namespace std;

int N, M;
int matrix[1000][1000];
bool visited[1000][1000][2]; //0이면 벽 안부순 것, 1이면 벽 부순 것
struct state { //처음엔 matrix를 갱신했는데 틀렸다고 해서...
    int col, row, crush, dist;
};
pair<int, int> dir[4] = {{-1, 0},  //상
                         {1,  0},  //하
                         {0,  -1}, //좌
                         {0,  1}}; //우

int bfs(state start) { //큐로 구현
    queue<state> q;

    q.push(start);
    while (!q.empty()) { //큐에 들어있는 모든 원소에 대해 가능한 방향 체크
        int col = q.front().col;
        int row = q.front().row;
        int crush = q.front().crush;
        int dist = q.front().dist;
        if ((col == N - 1) && (row == M - 1)) //break 가능한지 확인
            return dist;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nc = col + dir[i].first;
            int nr = row + dir[i].second;
            if ((nc >= 0) && (nc < N) && (nr >= 0) && (nr < M) && //범위 체크
                (matrix[nc][nr] == 0) && (visited[nc][nr][crush] == 0)) { //길을 만났을 때(이전에 벽을 부쉈을 수도 있고 아닐 수도 있음)
                int nd = dist + 1;
                visited[nc][nr][crush] = 1;
                q.push({nc, nr, crush, nd});
            } else if ((nc >= 0) && (nc < N) && (nr >= 0) && (nr < M) && //범위 체크
                       (crush == 0) && (matrix[nc][nr] == 1) && (visited[nc][nr][1] == 0)) { //벽을 안부순 상태에서 벽을 만났을 때
                int nd = dist + 1;
                visited[nc][nr][1] = 1;
                q.push({nc, nr, 1, nd});
            }
        }
    }
    return -1;
}

int main() {
    string tmp;

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        for (int j = 0; j < M; j++) {
            matrix[i][j] = tmp[j] - '0';
        }
    }
    visited[0][0][0] = 1; //첫 시작은 벽을 부수지 않았으니까
    state start = {0, 0, 0, 1};
    cout << bfs(start);
}