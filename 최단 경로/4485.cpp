#include <iostream>
#include <queue>
#include <vector>

using namespace std;
typedef pair<int, int> pp;

int N;
vector<vector<int>> board;
pp dir[4] = {{-1, 0},  //상
             {1,  0},  //하
             {0,  -1}, //좌
             {0,  1}}; //우

int dijkstra() {
    vector<vector<int>> min_dist(N, vector<int>(N, 1e9)); //최단 거리
    priority_queue<pair<int, pp>, vector<pair<int, pp>>, greater<>> pq; //min-heap
    min_dist[0][0] = board[0][0]; //초기화
    pq.push(make_pair(min_dist[0][0], make_pair(0, 0)));
    while (!pq.empty()) {
        int dist = pq.top().first;
        int row = pq.top().second.first;
        int col = pq.top().second.second;
        pq.pop();

        if (row == N - 1 && col == N - 1) //도착지점
            break;
        for (int i = 0; i < 4; i++) {
            int nr = row + dir[i].first;
            int nc = col + dir[i].second;
            if ((nr < 0) || (nr >= N) || (nc < 0) || (nc >= N)) //범위를 벗어남
                continue;
            int nd = dist + board[nr][nc]; //새로운 경로의 거리
            if (min_dist[nr][nc] > nd) { //이게 최단 경로라면 갱신
                min_dist[nr][nc] = nd;
                pq.push(make_pair(nd, make_pair(nr, nc)));
            }
        }
    }
    return min_dist[N - 1][N - 1]; //도착지점의 최단거리 리턴
}

int main() {
    int num = 1;

    while (true) {
        cin >> N;
        if (N == 0)
            break;
        board.assign(N, vector<int>(N));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                cin >> board[i][j];
        }
        cout << "Problem " << num++ << ": " << dijkstra() << '\n'; //다익스트라
    }
}