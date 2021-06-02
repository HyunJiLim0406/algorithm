#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;
typedef pair<int, int> pp;

pp dir_list[4] = {{0,  1},  //우
                  {-1, 0},  //상
                  {0,  -1}, //좌
                  {1,  0}}; //하
vector<vector<int>> board;
vector<pair<int, char>> dir_info;

int playGame(int size) {
    deque<pp> snake; //뱀의 정보
    int t = 0, idx = 0, dir_idx = 0; //시간, 회전 벡터 인덱스, 방향 인덱스
    snake.push_front(make_pair(0, 0)); //처음의 머리이자 꼬리
    board[0][0] = 1; //뱀 위치 표시

    while (true) {
        t++;
        int nr = snake.front().first + dir_list[dir_idx].first; //다음에 머리가 위치할 행
        int nc = snake.front().second + dir_list[dir_idx].second; //다음에 머리가 위치할 열
        if (nr < 0 || nr >= size || nc < 0 || nc >= size || board[nr][nc] == 1) //범위를 벗어나거나 자기자신이면 break
            break;
        if (board[nr][nc] != 2) { //사과가 없으면 꼬리 하나 지우기
            board[snake.back().first][snake.back().second] = 0;
            snake.pop_back();
        }
        snake.push_front(make_pair(nr, nc)); //새로운 머리 삽입
        board[nr][nc] = 1; //뱀 위치 표시
        if ((idx < dir_info.size()) && (t == dir_info[idx].first)) { //방향 바뀌는지 확인
            if (dir_info[idx].second == 'L') //왼쪽 회전
                dir_idx = (dir_idx + 1) % 4;
            else //오른쪽 회전
                dir_idx = (dir_idx + 3) % 4;
            idx++;
        }
    }
    return t;
}

int main() {
    int N, K, r, c, L, X;
    char C;

    cin >> N >> K;
    board.assign(N, vector<int>(N, 0));
    for (int i = 0; i < K; i++) {
        cin >> r >> c;
        board[r - 1][c - 1] = 2; //사과
    }
    cin >> L;
    for (int i = 0; i < L; i++) {
        cin >> X >> C;
        dir_info.emplace_back(X, C); //회전 정보
    }
    cout << playGame(N);
}