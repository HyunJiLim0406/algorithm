#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> pp;
const int INF = 1e9;

int N, result = INF;
vector<vector<int>> board, visited;
pp dir[4] = {{-1, 0},  //상
             {1,  0},  //하
             {0,  -1}, //좌
             {0,  1}}; //우

int bfs(queue<pp> q, int zero_cnt) {
    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        if (visited[r][c] >= result) //더이상 탐색할 가치 없음
            break;
        for (int i = 0; i < 4; i++) {
            int nr = r + dir[i].first;
            int nc = c + dir[i].second;
            if ((nr < 0) || (nr >= N) || (nc < 0) || (nc >= N)) //범위 벗어남
                continue;
            if (board[nr][nc] != 1 && visited[nr][nc] == -1) { //벽이 아니고, 방문한 적 없음
                visited[nr][nc] = visited[r][c] + 1; //거리 갱신
                if (board[nr][nc] == 0) { //빈 공간일 때
                    zero_cnt--;
                    if (!zero_cnt) //더이상 남은 빈 공간이 없음
                        return visited[nr][nc];
                }
                q.push(make_pair(nr, nc));
            }
        }
    }
    return result; //최솟값 갱신 안됨
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int M, zero_cnt = 0;
    vector<pp> virus_pos; //바이러스 위치

    cin >> N >> M;
    board.assign(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            if (board[i][j] == 0) //빈 공간
                zero_cnt++;
            else if (board[i][j] == 2) //바이러스
                virus_pos.emplace_back(i, j);
        }
    }
    if (zero_cnt == 0) { //빈 공간이 처음부터 없음
        cout << 0;
        return 0;
    }
    for (int i = 0; i < (1 << virus_pos.size()); i++) { //비트마스크로 바이러스 선택
        visited.assign(N, vector<int>(N, -1));
        queue<pp> tmp; //초기 활성 바이러스
        for (int j = 0; j < virus_pos.size(); j++) {
            if (i & (1 << j)) {
                tmp.push(virus_pos[j]);
                visited[virus_pos[j].first][virus_pos[j].second] = 0;
            }
        }
        if (tmp.size() != M) //M개의 바이러스가 아님
            continue;
        result = bfs(tmp, zero_cnt); //최솟값 갱신
    }
    cout << ((result == INF) ? -1 : result);
}