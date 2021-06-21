#include <iostream>
#include <vector>
#include <deque>
#include <string>

using namespace std;

struct info { //사람 여부, 행, 열
    bool is_human;
    int r, c;
};

int w, h;
vector<vector<char>> board;
pair<int, int> dir[4] = {{-1, 0},  //상
                         {1,  0},  //하
                         {0,  -1}, //좌
                         {0,  1}}; //우

int bfs(deque<info> dq) {
    vector<vector<int>> route(h, vector<int>(w, -1)); //초기화
    route[dq.back().r][dq.back().c] = 0;

    while (!dq.empty()) {
        info cur = dq.front();
        dq.pop_front();

        for (int i = 0; i < 4; i++) {
            int nr = cur.r + dir[i].first;
            int nc = cur.c + dir[i].second;
            if ((nr < 0) || (nr >= h) || (nc < 0) || (nc >= w)) { //범위를 벗어났을 때
                if (cur.is_human) //사람이라면 탈출 성공
                    return route[cur.r][cur.c] + 1;
                continue;
            }

            if (board[nr][nc] != '#' && board[nr][nc] != '*' && (!cur.is_human || route[nr][nc] == -1)) { //미방문 이동가능 지점
                if (!cur.is_human) //불 이동
                    board[nr][nc] = '*';
                else //사람 이동
                    route[nr][nc] = route[cur.r][cur.c] + 1;
                dq.push_back({cur.is_human, nr, nc});
            }
        }
    }
    return -1;
}

int main() {
    string input;
    int t;

    cin >> t;
    while (t--) {
        cin >> w >> h;
        board.assign(h, vector<char>(w));
        deque<info> init;
        for (int i = 0; i < h; i++) {
            cin >> input;
            for (int j = 0; j < w; j++) {
                board[i][j] = input[j];
                if (board[i][j] == '*') //불의 위치를 앞에 저장
                    init.push_front({false, i, j});
                else if (board[i][j] == '@') //사람의 위치를 뒤에 저장
                    init.push_back({true, i, j});
            }
        }
        int result = bfs(init);
        if (result == -1) //탈출 불가
            cout << "IMPOSSIBLE\n";
        else //탈출 가능
            cout << result << '\n';
    }
}