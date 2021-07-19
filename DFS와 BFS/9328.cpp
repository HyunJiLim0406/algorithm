#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> pp;

int h, w;
vector<bool> key; //보유한 열쇠
vector<vector<char>> board; //지도
pp dir[4] = {{-1, 0},  //상
             {1,  0},  //하
             {0,  -1}, //좌
             {0,  1}}; //우

int bfs() {
    int document = 0; //문서의 수
    queue<pp> q;
    queue<pp> doors[26]; //열리지 않은 문
    vector<vector<bool>> visited(h + 2, vector<bool>(w + 2, false));
    visited[0][0] = true; //초기화
    q.push(make_pair(0, 0));
    while (!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = row + dir[i].first;
            int nc = col + dir[i].second;
            if ((nr < 0) || (nr >= h + 2) || (nc < 0) || (nc >= w + 2) || visited[nr][nc] || board[nr][nc] == '*')
                continue;
            if (isupper(board[nr][nc]) && !key[board[nr][nc] - 'A']) { //문인데 열쇠가 없을 때
                doors[board[nr][nc] - 'A'].push(make_pair(nr, nc));
                continue;
            }
            if (board[nr][nc] == '$') //문서 발견
                document++;
            if (islower(board[nr][nc])) { //열쇠 발견
                key[board[nr][nc] - 'a'] = true; //열쇠 표시
                int idx = board[nr][nc] - 'a';
                while (!doors[idx].empty()) { //못 열었던 문 다 열기
                    pp door = doors[idx].front();
                    doors[idx].pop();

                    visited[door.first][door.second] = true; //방문 처리
                    q.push(door);
                }
            }
            visited[nr][nc] = true; //방문 처리
            q.push(make_pair(nr, nc));
        }
    }
    return document;
}

int main() {
    int t;
    string keys;

    cin >> t;
    while (t--) {
        cin >> h >> w;
        board.assign(h + 2, vector<char>(w + 2, '.'));
        key.assign(26, false);
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++)
                cin >> board[i][j];
        }
        cin >> keys;
        if (keys != "0") {
            for (int i = 0; i < keys.size(); i++)
                key[keys[i] - 'a'] = true;
        }
        cout << bfs() << '\n';
    }
}