#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int R, C;
vector<vector<int>> map, tmp_map;
pair<int, int> dir[4] = {{-1, 0},
                         {1,  0},
                         {0,  -1},
                         {0,  1}};

void spreadAir(pair<int, int> pos) { //실제 map에 바로 적용하지 않고 따로 저장해둠
    int cnt = 0;
    int spread = map[pos.first][pos.second] / 5;

    for (int i = 0; i < 4; i++) {
        int nr = pos.first + dir[i].first;
        int nc = pos.second + dir[i].second;
        if ((nr >= 0) && (nr < R) && (nc >= 0) && (nc < C) && (map[nr][nc] != -1)) {
            tmp_map[nr][nc] += spread;
            cnt++;
        }
    }
    map[pos.first][pos.second] -= (cnt * spread);
}

int main() {
    int T;
    vector<int> air;

    cin >> R >> C >> T;
    map.assign(R, vector<int>(C));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> map[i][j];
            if (map[i][j] == -1)
                air.push_back(i);
        }
    }
    for (int t = 0; t < T; t++) {
        tmp_map.assign(R, vector<int>(C, 0));
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (map[i][j] > 0) //미세먼지 확산 정도 tmp_map에 저장
                    spreadAir(make_pair(i, j));
            }
        }
        for (int i = 0; i < R; i++) { //실제로 미세먼지 확산시키기
            for (int j = 0; j < C; j++)
                map[i][j] += tmp_map[i][j];
        }

        //반시계 방향 순환
        for (int i = air[0] - 2; i >= 0; i--)
            map[i + 1][0] = map[i][0];
        for (int i = 1; i < C; i++)
            map[0][i - 1] = map[0][i];
        for (int i = 1; i <= air[0]; i++)
            map[i - 1][C - 1] = map[i][C - 1];
        for (int i = C - 2; i >= 1; i--)
            map[air[0]][i + 1] = map[air[0]][i];
        map[air[0]][1] = 0;

        //시계 방향 순환
        for (int i = air[1] + 2; i < R; i++)
            map[i - 1][0] = map[i][0];
        for (int i = 1; i < C; i++)
            map[R - 1][i - 1] = map[R - 1][i];
        for (int i = R - 2; i >= air[1]; i--)
            map[i + 1][C - 1] = map[i][C - 1];
        for (int i = C - 2; i >= 1; i--)
            map[air[1]][i + 1] = map[air[1]][i];
        map[air[1]][1] = 0;
    }
    int cnt_dust = 0; //미세먼지 계산
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (map[i][j] != -1)
                cnt_dust += map[i][j];
        }
    }
    cout << cnt_dust;
}