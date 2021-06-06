#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pp;

int N, M, result = 65;
vector<vector<int>> board;
vector<pp> cctv; //cctv 위치
pp direction[4] = {{-1, 0},   //상
                   {0,  1},   //우
                   {1,  0},   //하
                   {0,  -1}}; //좌

void ray(pp pos, int dir) {
    int row = pos.first;
    int col = pos.second;
    while (true) { //특정 방향으로 뻗어나가며 cctv의 범위 확인
        row += direction[dir].first;
        col += direction[dir].second;
        if ((row < 0) || (row >= N) || (col < 0) || (col >= M) || (board[row][col] == 6)) //범위를 벗어나거나 벽
            break;
        if (board[row][col] == 0) //다른 cctv를 지우지 않기 위해 빈 공간일 때만 방문 표시
            board[row][col] = 7;
    }
}

void install(pp pos, int dir) {
    int cur = board[pos.first][pos.second];
    if (cur >= 1) //1, 2, 3, 4, 5번 cctv
        ray(pos, dir);
    if (cur >= 2 && cur != 3) //2, 4, 5번 cctv
        ray(pos, (dir + 2) % 4);
    if (cur >= 3) //3, 4, 5번 cctv
        ray(pos, (dir + 1) % 4);
    if (cur == 5) //5번 cctv
        ray(pos, (dir + 3) % 4);
}

void backtracking(int idx) {
    if (idx == cctv.size()) { //모든 cctv 배치
        int cnt = 0; //사각지대 세기
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (board[i][j] == 0)
                    cnt++;
            }
        }
        result = min(result, cnt); //최솟값 갱신
        return;
    }
    vector<vector<int>> tmp = board; //복사
    int cur_cctv = board[cctv[idx].first][cctv[idx].second];
    for (int i = 0; i < 4; i++) {
        install(cctv[idx], i); //visited 처리
        backtracking(idx + 1); //재귀 호출
        board = tmp; //unvisited 처리
        if ((cur_cctv == 2 && i == 1) || (cur_cctv == 5 && i == 0)) //2번 cctv는 2개의 방향만, 5번 cctv는 1개의 방향만 체크
            break;
    }
}

int main() {
    cin >> N >> M;
    board.assign(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j] > 0 && board[i][j] < 6) //cctv 입력
                cctv.emplace_back(i, j);
        }
    }
    backtracking(0);
    cout << result;
}