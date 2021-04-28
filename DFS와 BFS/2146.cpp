#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

vector<vector<int>> map; //지도
vector<pair<int, int>> side_land; //가장자리에 있는 땅들
int min_block = 1000, N;
pair<int, int> dir[4] = {{-1, 0},  //상
                         {1,  0},  //하
                         {0,  -1}, //좌
                         {0,  1}}; //우

void dfs(pair<int, int> cur, int mark) { //각 섬마다 다르게 마크
    bool isSide = false; //가장자리의 땅인가?
    int row = cur.first;
    int col = cur.second;

    map[row][col] = mark; //구역 체크
    for (int i = 0; i < 4; i++) {
        int nr = row + dir[i].first;
        int nc = col + dir[i].second;
        if ((nr >= 0) && (nr < N) && (nc >= 0) && (nc < N)) { //범위 체크
            if ((map[nr][nc] == 0) && !isSide) { //물이 있으면 가장자리 땅. 중복 투입 막기 위해 isSide 사용
                isSide = true;
                side_land.push_back(make_pair(row, col));
            } else if (map[nr][nc] == 1) //연결된 땅이 있으면 dfs
                dfs(make_pair(nr, nc), mark);
        }
    }
}

void bfs(pair<int, int> start, int mark) {
    vector<vector<int>> dist; //거리 저장
    queue<pair<int, int>> q;
    dist.assign(N, vector<int>(N, 0));

    q.push(start);
    dist[start.first][start.second] = 0; //시작점은 0
    while (!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        if ((map[row][col] < 0) && (map[row][col] != mark)) { //마크가 다른 땅이면 새로운 땅에 닿은 것
            min_block = dist[row][col];
            return;
        }
        for (int i = 0; i < 4; i++) {
            int nr = row + dir[i].first;
            int nc = col + dir[i].second;
            if ((nr >= 0) && (nr < N) && (nc >= 0) && (nc < N) && (map[nr][nc] != mark) && (dist[nr][nc] == 0)) { //새로운 섬이거나, 물이거나
                dist[nr][nc] = dist[row][col] + 1;
                if (dist[nr][nc] > min_block) //현재의 가장 짧은 다리보다 길면 더이상 탐색할 필요가 없음
                    return;
                q.push(make_pair(nr, nc));
            }
        }
    }
}

int main() {
    int mark = 0; //각 섬마다 -1, -2,...로 마크

    cin >> N;
    map.assign(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cin >> map[i][j];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 1) { //체크가 안된 땅에 대해 dfs로 섬 찾기
                mark--;
                dfs(make_pair(i, j), mark);
            }
        }
    }
    for (int i = 0; i < side_land.size(); i++) //가장자리 땅들에 대해 bfs
        bfs(side_land[i], map[side_land[i].first][side_land[i].second]);
    cout << min_block - 1;
}