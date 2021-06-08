#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> pp;

int N, M;
vector<vector<int>> board, idx; //지도, 각 좌표별 녹게될 얼음의 양 겸 방문 체크
pp dir[4] = {{-1, 0},  //상
             {1,  0},  //하
             {0,  -1}, //좌
             {0,  1}}; //우

int meltAmount(pp pos) { //이번 해에 얼마나 녹게 될까
    int cnt = 0;
    for (int i = 0; i < 4; i++) {
        int row = pos.first + dir[i].first;
        int col = pos.second + dir[i].second;
        if ((row >= 0) && (row < N) && (col >= 0) && (col < M) && !board[row][col]) //범위 내에 있고 바다임
            cnt++;
    }
    return cnt;
}

void melting() { //빙하 녹이기
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            board[i][j] = (board[i][j] - idx[i][j] < 0) ? 0 : board[i][j] - idx[i][j]; //음수가 되지 않도록
    }
}

void dfs(pp cur) {
    int row = cur.first;
    int col = cur.second;
    idx[row][col] = -1; //방문 표시
    for (int i = 0; i < 4; i++) {
        int nr = row + dir[i].first;
        int nc = col + dir[i].second;
        if ((nr >= 0) && (nr < N) && (nc >= 0) && (nc < M) && (idx[nr][nc] >= 0) && board[nr][nc]) //범위 내에 있고 미방문 빙하
            dfs(make_pair(nr, nc));
    }
}

int cntGroup() {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if ((idx[i][j] >= 0) && board[i][j]) { //미방문 빙하라면
                cnt++;
                dfs(make_pair(i, j));
            }
        }
    }
    return cnt; //그룹의 수 리턴
}

int main() {
    cin >> N >> M;
    board.assign(N, vector<int>(M, 0));
    idx.assign(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            cin >> board[i][j];
    }
    int year = 0;
    while (true) {
        year++; //년도 증가
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (board[i][j]) //빙하라면 다음에 녹게될 양 계산
                    idx[i][j] = meltAmount(make_pair(i, j));
            }
        }
        melting(); //빙하 녹이기
        int group = cntGroup(); //빙산의 그룹 계산
        if (group != 1) { //그룹의 수가 1이 아니라면 break
            if (group == 0) //모든 빙하가 녹음
                year = 0;
            break;
        }
    }
    cout << year;
}