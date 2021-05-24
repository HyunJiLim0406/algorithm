#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
typedef pair<int, int> pp;

int result = 11;
vector<vector<char>> board;
pp dir[4] = {{-1, 0},  //상
             {1,  0},  //하
             {0,  -1}, //좌
             {0,  1}}; //우

pp newPos(pp pos, int d) {
    int r = pos.first; //행
    int c = pos.second; //열
    while ((board[r][c] != '#') && (board[r][c] != 'O')) { //벽 또는 구멍을 만날 때까지 이동
        r += dir[d].first;
        c += dir[d].second;
    }
    if (board[r][c] == 'O') //구멍에 빠짐
        return make_pair(-1, -1);
    return make_pair(r - dir[d].first, c - dir[d].second); //벽을 만남
}

int forwardMarble(vector<pp> marble, int d) { //특정 방향에 대해 어떤 구슬이 앞에 있었는지
    int r = marble[0].first - marble[1].first;
    int c = marble[0].second - marble[1].second;
    if (((r ^ dir[d].first) >= 0) && ((c ^ dir[d].second) >= 0)) //r, c의 부호가 dir과 같다면 빨간 구슬이 앞에 있었던 것
        return 1;
    return 0;
}

void backtracking(int cnt, vector<pp> marble, int before_dir) {
    if (cnt >= result) //cnt가 result 이상이라면 더이상 탐색할 필요 없음
        return;
    vector<pp> new_pos; //각 구슬의 새로운 위치
    new_pos.assign(2, make_pair(0, 0));
    for (int i = 0; i < 4; i++) {
        if (i == before_dir) //직전과 같은 방향은 탐색할 필요 없음
            continue;
        int kept_cnt = 0; //위치 변화 없는 구슬의 수
        for (int j = 0; j < 2; j++) {
            new_pos[j] = newPos(marble[j], i);
            if ((new_pos[j].first == marble[j].first) && (new_pos[j].second == marble[j].second)) //위치 변화 없음
                kept_cnt++;
        }
        if ((kept_cnt == 2) ||
            ((new_pos[1].first == -1) && (new_pos[1].second == -1))) //두 구슬 모두 위치가 그대로거나 파란 구슬이 구멍에 빠졌을 때
            continue;
        if ((new_pos[0].first == -1) && (new_pos[0].second == -1)) { //빨간 구슬이 구멍에 빠졌다면 최솟값 갱신
            result = min(result, cnt + 1);
            return;
        } else {
            if ((new_pos[0].first == new_pos[1].first) &&
                (new_pos[0].second == new_pos[1].second)) { //두 구슬의 새로운 위치가 같다면
                int backward_marble = forwardMarble(marble, i); //뒤에 있는 구슬의 인덱스
                new_pos[backward_marble].first -= dir[i].first;
                new_pos[backward_marble].second -= dir[i].second;
            }
            backtracking(cnt + 1, new_pos, i); //새로운 위치에 대한 백트래킹 호출
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    string input;
    vector<pp> marble; //구슬의 초기 위치

    cin >> N >> M;
    board.assign(N, vector<char>(M));
    marble.assign(2, make_pair(0, 0));
    for (int i = 0; i < N; i++) {
        cin >> input;
        for (int j = 0; j < M; j++) {
            board[i][j] = input[j];
            if (board[i][j] == 'R') //빨간 구슬
                marble[0] = make_pair(i, j);
            else if (board[i][j] == 'B') //파란 구슬
                marble[1] = make_pair(i, j);
        }
    }
    backtracking(0, marble, -1); //백트래킹
    cout << ((result == 11) ? -1 : result);
}