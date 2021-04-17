#include <iostream>
#include <string>
#include <queue>
#include <utility>

using namespace std;

struct pos_info { //열, 행, 물 or 고슴도치
    int col_s, row_s, status_s;
};
int R, C;
char map[50][50]; //지도
int dist[50][50]; //고슴도치의 이동
pair<int, int> dir[4] = {{-1, 0},  //상
                         {1,  0},  //하
                         {0,  -1}, //좌
                         {0,  1}}; //우

int bfs(pos_info start, pos_info end, vector<pos_info> water) {
    queue<pos_info> q;

    for (int i = 0; i < water.size(); i++) //물 정보 먼저 넣고
        q.push(water[i]);
    q.push(start); //고슴도치 정보 투입
    while (!q.empty()) {
        int col = q.front().col_s;
        int row = q.front().row_s;
        int status = q.front().status_s;
        if (dist[end.col_s][end.row_s]) //도착점의 dist 값이 0이 아니면
            return dist[end.col_s][end.row_s];
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nc = col + dir[i].first;
            int nr = row + dir[i].second;
            if ((nc >= 0) && (nc < R) && (nr >= 0) && (nr < C)) { //범위 확인
                if (status == 0 && (dist[nc][nr] == 0) && ((map[nc][nr] == '.') || (map[nc][nr] == 'D'))) { //고슴도치 이동
                    dist[nc][nr] = dist[col][row] + 1;
                    q.push({nc, nr, status});
                } else if (status == 1 && (map[nc][nr] == '.')) { //홍수 이동
                    map[nc][nr] = '*';
                    q.push({nc, nr, status});
                }
            }
        }
    }
    return 0;
}

int main() {
    string tmp;
    pos_info start, end;
    vector<pos_info> water;

    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        cin >> tmp;
        for (int j = 0; j < C; j++) {
            map[i][j] = tmp[j];
            if (map[i][j] == 'S') //시작점
                start = {i, j, 0};
            else if (map[i][j] == 'D') //도착점
                end = {i, j, 0};
            else if (map[i][j] == '*') //홍수
                water.push_back({i, j, 1});
        }
    }
    int result = bfs(start, end, water);
    if (result == 0) //길이 없음
        cout << "KAKTUS\n";
    else //출력 가능
        cout << result;
}