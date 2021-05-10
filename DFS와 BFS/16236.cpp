#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

vector<vector<int>> board;
int shark_size = 2; //상어의 크기
int fish_cnt, result; //먹은 물고기의 수, 이동하는데 걸린 총 시간
pair<int, int> dir[4] = {{-1, 0},  //상
                         {1,  0},  //하
                         {0,  -1}, //좌
                         {0,  1}}; //우

bool cmp(const pair<int, int> &p1, const pair<int, int> &p2) { //정렬
    if (p1.first == p2.first)
        return p1.second < p2.second;
    return p1.first < p2.first;
}

pair<int, int> bfs(pair<int, int> shark) {
    int size = board.size(), min_dist = 1000;
    queue<pair<int, int>> q; //상어가 갈 수 있는 곳을 담은 큐
    vector<vector<int>> dist; //상어의 방문 여부 및 이동 거리
    dist.assign(size, vector<int>(size, -1));
    vector<pair<int, int>> candi; //상어가 최종적으로 이동할 곳의 후보

    dist[shark.first][shark.second] = 0;
    q.push(shark);
    while (!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        if (dist[row][col] < min_dist) { //dist[row][col]이 min_dist 이상이라면, 물고기가 있어도 최단거리가 아님
            for (int i = 0; i < 4; i++) {
                int nr = row + dir[i].first;
                int nc = col + dir[i].second;
                if ((nr >= 0) && (nr < size) && (nc >= 0) && (nc < size) && (dist[nr][nc] == -1) && //범위 내에 있는 미방문 좌표
                    (board[nr][nc] <= shark_size)) { //상어가 갈 수 있다면
                    dist[nr][nc] = dist[row][col] + 1; //거리 갱신
                    if ((board[nr][nc] > 0) && (board[nr][nc] < shark_size)) { //상어가 먹을 수 있는 물고기라면
                        candi.push_back(make_pair(nr, nc)); //최종 이동 후보에 넣음
                        min_dist = dist[nr][nc]; //최단 거리 갱신
                    }
                    if (dist[nr][nc] < min_dist) //먹을 수 있는 물고기를 찾았다면 더 나갈 필요 없음
                        q.push(make_pair(nr, nc));
                }
            }
        }
    }
    if (candi.empty()) //후보 배열이 비어있다면 상어가 이동할 수 없는 것
        return make_pair(-1, -1);

    sort(candi.begin(), candi.end(), cmp); //정렬
    fish_cnt++; //먹은 물고기의 수 증가
    if (fish_cnt == shark_size) { //먹은 물고기의 수가 상어의 크기와 같다면
        fish_cnt = 0;
        shark_size++;
    }
    board[candi[0].first][candi[0].second] = 9; //상어 이동
    board[shark.first][shark.second] = 0; //상어의 원래 위치 0으로 변경
    result += min_dist; //활동 시간 증가
    return make_pair(candi[0].first, candi[0].second); //상어의 새로운 위치 반환
}

int main() {
    int N;
    pair<int, int> shark_pos;

    cin >> N;
    board.assign(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            if (board[i][j] == 9) //상어의 초기 위치
                shark_pos = make_pair(i, j);
        }
    }
    while ((shark_pos.first != -1) && (shark_pos.second != -1)) //상어가 더 이동할 수 없을 때까지 이동
        shark_pos = bfs(shark_pos);
    cout << result;
}