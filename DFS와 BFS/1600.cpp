#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> pp;

struct monkey_info { //원숭이 정보. 행, 열, 말처럼 이동한 횟수, 이동 거리
    int r, c, h, d;
};

int K, W, H;
vector<vector<int>> board, horse_cnt;
pp dir[4] = {{-1, 0},
             {1,  0},
             {0,  -1},
             {0,  1}};
pp horse_dir[8] = {{-1, -2},
                   {-2, -1},
                   {-2, 1},
                   {-1, 2},
                   {1,  -2},
                   {2,  -1},
                   {2,  1},
                   {1,  2}};

bool isPromise(int r, int c, int h) { //해당 위치로 이동할 수 있는지 확인
    if (r < 0 || r >= H || c < 0 || c >= W || board[r][c] || horse_cnt[r][c] <= h)
        return false;
    return true;
}

int bfs() {
    horse_cnt.assign(H, vector<int>(W, K + 1));
    queue<monkey_info> q;
    q.push({0, 0, 0, 0});
    horse_cnt[0][0] = 0; //시작점 초기화

    while (!q.empty()) {
        int row = q.front().r;
        int col = q.front().c;
        int horse = q.front().h;
        int dist = q.front().d;
        q.pop();

        if (row == H - 1 && col == W - 1) //목표지점 도달
            return dist;
        for (int i = 0; i < 4; i++) { //인접 지점으로 이동
            int nr = row + dir[i].first;
            int nc = col + dir[i].second;
            if (isPromise(nr, nc, horse)) {
                horse_cnt[nr][nc] = horse;
                q.push({nr, nc, horse, dist + 1});
            }
        }
        if (horse >= K) //말처럼 이동할 수 있는 횟수 남아있는지?
            continue;
        for (int i = 0; i < 8; i++) { //말처럼 이동
            int nr = row + horse_dir[i].first;
            int nc = col + horse_dir[i].second;
            if (isPromise(nr, nc, horse + 1)) {
                horse_cnt[nr][nc] = horse + 1;
                q.push({nr, nc, horse + 1, dist + 1});
            }
        }
    }
    return -1;
}

int main() {
    cin >> K >> W >> H;
    board.assign(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++)
            cin >> board[i][j];
    }
    cout << bfs();
}