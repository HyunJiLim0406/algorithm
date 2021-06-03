#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> pp;

int clean_cnt; //청소 횟수
bool is_stopped; //동작 정지 여부
vector<vector<int>> board;
vector<vector<bool>> is_cleaned;
pp dir[4] = {{-1, 0},   //북
             {0,  1},   //동
             {1,  0},   //남
             {0,  -1}}; //서

void moveRobot(pp cur_pos, int cur_dir) {
    int row = cur_pos.first;
    int col = cur_pos.second;
    if (!is_cleaned[row][col]) { //아직 청소하지 않음
        is_cleaned[row][col] = true;
        clean_cnt++;
    }
    int next_dir = (cur_dir + 3) % 4; //현재 방향의 왼쪽
    do {
        int nr = row + dir[next_dir].first;
        int nc = col + dir[next_dir].second;
        if (board[nr][nc] || is_cleaned[nr][nc]) //벽이거나 청소했으면 다음 방향 확인
            next_dir = (next_dir + 3) % 4;
        else //재귀 호출
            moveRobot(make_pair(nr, nc), next_dir);
        if (is_stopped) //작동 정지 확인
            return;
    } while (next_dir != (cur_dir + 3) % 4); //4번 확인

    int back_dir = (cur_dir + 2) % 4; //후진 방향
    int br = row + dir[back_dir].first;
    int bc = col + dir[back_dir].second;
    if (board[br][bc]) { //후진할 수 없음
        is_stopped = true;
        return;
    }
    moveRobot(make_pair(br, bc), cur_dir); //후진 호출
}

int main() {
    int N, M, init_dir;
    pp init_pos;

    cin >> N >> M;
    board.assign(N, vector<int>(M, 0));
    is_cleaned.assign(N, vector<bool>(M, false));
    cin >> init_pos.first >> init_pos.second >> init_dir;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            cin >> board[i][j];
    }
    moveRobot(init_pos, init_dir);
    cout << clean_cnt;
}