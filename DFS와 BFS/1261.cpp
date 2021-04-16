#include <iostream>
#include <string>
#include <deque>
#include <utility>

using namespace std;

struct pos_info { //열, 행, 파괴 횟수
    int col_c, row_c, crush_c;
};

int N, M;
int matrix[100][100]; //-1:방문, 0:길, 1:벽
pair<int, int> dir[4] = {{-1, 0},  //상
                         {1,  0},  //하
                         {0,  -1}, //좌
                         {0,  1}}; //우

int bfs() {
    deque<pos_info> dq;

    dq.push_back({0, 0, 0});
    matrix[0][0] = -1; //visited 처리
    while (!dq.empty()) {
        int col = dq.front().col_c;
        int row = dq.front().row_c;
        int crush = dq.front().crush_c;
        dq.pop_front();
        if ((col == (N - 1)) && (row == (M - 1))) //종료 조건
            return crush;

        for (int i = 0; i < 4; i++) {
            int nc = col + dir[i].first;
            int nr = row + dir[i].second;
            if ((nc >= 0) && (nc < N) && (nr >= 0) && (nr < M)) { //범위 내에 들어왔고
                if (matrix[nc][nr] == 0) { //길이라면
                    matrix[nc][nr] = -1;
                    dq.push_front({nc, nr, crush}); //우선 처리
                } else if (matrix[nc][nr] == 1) { //벽이라면
                    matrix[nc][nr] = -1;
                    dq.push_back({nc, nr, crush + 1}); //후순위 처리
                }
            }
        }
    }
    return 0;
}

int main() {
    string tmp;

    cin >> M >> N;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        for (int j = 0; j < M; j++)
            matrix[i][j] = tmp[j] - '0';
    }
    cout << bfs();
}