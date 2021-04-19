#include <iostream>
#include <string>
#include <queue>
#include <utility>

using namespace std;

int R, C;
char map[50][50]; //지도
int dist[50][50]; //고슴도치의 이동
pair<int, int> dir[4] = {{-1, 0},  //상
                         {1,  0},  //하
                         {0,  -1}, //좌
                         {0,  1}}; //우

int bfs(pair<int, int> start, pair<int, int> end, vector<pair<int, int>> water) {
    queue<pair<int, int>> q;

    for (int i = 0; i < water.size(); i++) //물 정보 먼저 넣고
        q.push(water[i]);
    q.push(start); //고슴도치 정보 투입
    dist[start.first][start.second] = 1; //시작점 visited 체크
    while (!q.empty()) {
        int col = q.front().first;
        int row = q.front().second;
        if (dist[end.first][end.second]) //도착점의 dist 값이 0이 아니면
            return dist[end.first][end.second] - 1;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nc = col + dir[i].first;
            int nr = row + dir[i].second;
            if ((nc >= 0) && (nc < R) && (nr >= 0) && (nr < C)) { //범위 확인
                if ((dist[col][row] != 0) && (dist[nc][nr] == 0) &&
                    ((map[nc][nr] == '.') || (map[nc][nr] == 'D'))) { //고슴도치 이동
                    dist[nc][nr] = dist[col][row] + 1;
                    q.push(make_pair(nc, nr));
                } else if ((map[col][row] == '*') && (map[nc][nr] == '.')) { //홍수 이동
                    map[nc][nr] = '*';
                    q.push(make_pair(nc, nr));
                }
            }
        }
    }
    return 0;
}

int main() {
    string tmp;
    pair<int, int> start, end;
    vector<pair<int, int>> water;

    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        cin >> tmp;
        for (int j = 0; j < C; j++) {
            map[i][j] = tmp[j];
            if (map[i][j] == 'S') //시작점
                start = make_pair(i, j);
            else if (map[i][j] == 'D') //도착점
                end = make_pair(i, j);
            else if (map[i][j] == '*') //홍수
                water.push_back(make_pair(i, j));
        }
    }
    int result = bfs(start, end, water);
    if (result == 0) //길이 없음
        cout << "KAKTUS\n";
    else //출력 가능
        cout << result;
}