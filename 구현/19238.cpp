#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
const int MAX_DIST = 500;
typedef pair<int, int> pp;

int N, fuel;
vector<vector<int>> board;
pp dir[4] = {{-1, 0},  //상
             {1,  0},  //하
             {0,  -1}, //좌
             {0,  1}}; //우

pair<pp, int> bfs(pp start, pp target) {
    vector<pp> candi; //지점의 후보
    vector<vector<int>> visited(N + 1, vector<int>(N + 1, -1));
    int min_dist = MAX_DIST;
    queue<pp> q;
    visited[start.first][start.second] = 0; //시작점 초기화
    q.push(start);
    while (!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        if (make_pair(row, col) == target) { //손님 태운 후 : 목적지 도달
            min_dist = visited[row][col];
            candi.emplace_back(row, col);
            break;
        }
        if (visited[row][col] > min_dist) //손님 찾을 때 : 현재까지의 최단거리보다 길면 탐색 X
            continue;
        if (target == make_pair(0, 0) && board[row][col] >= 2) { //손님 찾을 때 : 최단거리의 손님이라면 후보에 넣기
            min_dist = visited[row][col];
            candi.emplace_back(row, col);
            continue;
        }
        for (int i = 0; i < 4; i++) {
            int nr = row + dir[i].first;
            int nc = col + dir[i].second;
            if ((nr <= 0) || (nr > N) || (nc <= 0) || (nc > N) || (visited[nr][nc] != -1) || (board[nr][nc] == 1))
                continue;
            visited[nr][nc] = visited[row][col] + 1;
            q.push(make_pair(nr, nc));
        }
    }
    fuel -= min_dist; //연료 소모
    if (candi.empty()) //손님에게 가지 못하거나, 목적지에 가지 못함
        return make_pair(start, min_dist);
    sort(candi.begin(), candi.end()); //정렬
    return make_pair(candi[0], min_dist); //택시의 새로운 위치, 거기까지의 거리 리턴
}

int main() {
    int M, sr, sc, dr, dc;
    pp taxi;

    cin >> N >> M >> fuel;
    board.assign(N + 1, vector<int>(N + 1));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++)
            cin >> board[i][j];
    }
    cin >> taxi.first >> taxi.second; //택시의 초기 위치
    vector<pp> customers(M + 2); //각 손님의 목적지
    for (int i = 0; i < M; i++) {
        cin >> sr >> sc >> dr >> dc;
        customers[i + 2] = make_pair(dr, dc); //목적지 저장
        board[sr][sc] = i + 2; //지도에 손님 출발지 표시
    }
    while (M--) {
        pp target = make_pair(0, 0); //태울 손님 찾기
        for (int i = 0; i < 2; i++) {
            pair<pp, int> result = bfs(taxi, target); //택시의 새로운 위치와 거기까지의 거리
            pp n_pos = result.first; //새로운 위치
            if (fuel < 0 || result.second == MAX_DIST) { //연료 부족하거나, 목적지에 가지 못함
                cout << -1;
                return 0;
            }
            taxi = n_pos; //택시 위치 갱신
            target = customers[board[n_pos.first][n_pos.second]]; //태운 손님의 목적지
            if (i == 0) //손님을 태울 때라면 지도 갱신
                board[n_pos.first][n_pos.second] = 0;
            else //손님을 목적지에 데려다 준 후라면 연료 갱신
                fuel += (result.second * 2);
        }
    }
    cout << fuel;
}