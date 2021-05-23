#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pp;

vector<vector<char>> board;
int N, M, result = 11;
pp dir[4] = {{-1, 0},  //상
             {1,  0},  //하
             {0,  -1}, //좌
             {0,  1}}; //우

pp nextPos(pp pos, int idx) { //다음 번에 이동하게 될 좌표
    int row = pos.first + dir[idx].first;
    int col = pos.second + dir[idx].second;
    if ((row < 0) || (row >= N) || (col < 0) || (col >= M)) //밖으로 떨어짐
        return make_pair(-1, -1);
    if (board[row][col] == '#') //벽을 만남
        return pos;
    return make_pair(row, col); //이동 가능
}

void backtracking(int cnt, vector<pp> cur_pos) {
    if (cnt >= result) //cnt 최솟값보다 같거나 크다면 더이상 탐색할 필요 없음
        return;

    vector<pp> new_pos;
    new_pos.assign(2, make_pair(0, 0));
    for (int i = 0; i < 4; i++) {
        int out_cnt = 0, same_cnt = 0;
        for (int j = 0; j < 2; j++) {
            new_pos[j] = nextPos(cur_pos[j], i); //각 동전의 새로운 위치에 대해
            if ((new_pos[j].first == -1) && (new_pos[j].second == -1)) //밖으로 떨어졌다면
                out_cnt++;
            else if ((new_pos[j].first == cur_pos[j].first) && (new_pos[j].second == cur_pos[j].second)) //변화가 없다면(벽)
                same_cnt++;
        }
        if (same_cnt == 2) //두 동전 모두 위치 변화가 없을 때
            continue;
        if (out_cnt == 1) //두 동전 중 하나만 떨어졌을 때, result 갱신
            result = min(result, cnt + 1);
        else if (out_cnt == 0) //두 동전 모두 떨어지지 않았을 때 백트래킹 탐색
            backtracking(cnt + 1, new_pos);
    }
}

int main() {
    vector<pp> coin; //동전의 초기 위치

    cin >> N >> M;
    board.assign(N, vector<char>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'o') //동전 위치 저장
                coin.push_back(make_pair(i, j));
        }
    }
    backtracking(0, coin);
    cout << ((result == 11) ? -1 : result); //result 갱신된 적 없으면 -1 출력
}