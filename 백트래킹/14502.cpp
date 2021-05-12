#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
typedef pair<int, int> pp;

vector<vector<int>> board, tmp_board; //원래의 연구소와 시뮬레이션 할 연구소
vector<pp> virus_pos; //바이러스의 위치
vector<pp> empty_pos; //빈 공간의 위치
int N, M, max_empty;
pp dir[4] = {{-1, 0},  //상
             {1,  0},  //하
             {0,  -1}, //좌
             {0,  1}}; //우

void dfs(pp cur) { //바이러스를 퍼뜨리는 dfs
    for (int i = 0; i < 4; i++) {
        int nr = cur.first + dir[i].first;
        int nc = cur.second + dir[i].second;
        if ((nr >= 0) && (nr < N) && (nc >= 0) && (nc < M) && (tmp_board[nr][nc] == 0)) { //범위 내에 있는 빈 공간이면 바이러스 퍼뜨리기
            tmp_board[nr][nc] = 2;
            dfs(make_pair(nr, nc));
        }
    }
}

void backtracking(int idx, int cnt) { //가능한 모든 벽의 경우의 수를 탐색
    if (cnt == 3) { //벽을 3개 세웠으면
        tmp_board = board; //현재의 연구소 복사
        for (int i = 0; i < virus_pos.size(); i++) //모든 바이러스 퍼뜨려보기
            dfs(virus_pos[i]);
        int cnt = 0; //남은 빈 공간 세기
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (tmp_board[i][j] == 0)
                    cnt++;
            }
        }
        max_empty = max(max_empty, cnt); //최댓값 갱신
        return;
    }
    for (int i = idx + 1; i < empty_pos.size(); i++) {
        pp cur_pos = empty_pos[i];
        board[cur_pos.first][cur_pos.second] = 1; //visited 처리
        backtracking(i, cnt + 1);
        board[cur_pos.first][cur_pos.second] = 0; //unvisited 처리
    }
}

int main() {
    cin >> N >> M;
    board.assign(N, vector<int>(M, 0));
    tmp_board.assign(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j] == 0) //빈 공간 위치 입력
                empty_pos.push_back(make_pair(i, j));
            else if (board[i][j] == 2) //바이러스 위치 입력
                virus_pos.push_back(make_pair(i, j));
        }
    }
    backtracking(-1, 0);
    cout << max_empty;
}