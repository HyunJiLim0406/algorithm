#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <tuple>

using namespace std;
typedef tuple<int, int, int> tp;

int L, R, C;
vector<vector<vector<char>>> board;
vector<vector<vector<int>>> dist;
tp dir[6] = {{-1, 0,  0},  //북
             {1,  0,  0},  //남
             {0,  -1, 0},  //서
             {0,  1,  0},  //동
             {0,  0,  -1}, //상
             {0,  0,  1}}; //하

int bfs(tp start) {
    queue<tp> q;
    dist[get<0>(start)][get<1>(start)][get<2>(start)] = 1; //시작점
    q.push(start);
    while (!q.empty()) {
        int row = get<0>(q.front()); //행
        int col = get<1>(q.front()); //열
        int floor = get<2>(q.front()); //층
        q.pop();

        if (board[row][col][floor] == 'E') //출구
            return dist[row][col][floor] - 1;
        for (int i = 0; i < 6; i++) {
            int nr = row + get<0>(dir[i]);
            int nc = col + get<1>(dir[i]);
            int nf = floor + get<2>(dir[i]);
            if ((nr < 0) || (nr >= R) || (nc < 0) || (nc >= C) || (nf < 0) || (nf >= L)) //범위 벗어남
                continue;
            if (board[nr][nc][nf] != '#' && !dist[nr][nc][nf]) { //이동 가능
                dist[nr][nc][nf] = dist[row][col][floor] + 1;
                q.push(make_tuple(nr, nc, nf));
            }
        }
    }
    return -1; //갇힘
}

int main() {
    string input;

    while (true) {
        cin >> L >> R >> C;
        if (!L && !R && !C) //while문 종료 조건
            break;
        board.assign(R, vector<vector<char>>(C, vector<char>(L)));
        dist.assign(R, vector<vector<int>>(C, vector<int>(L)));
        tp start;
        for (int k = 0; k < L; k++) {
            for (int i = 0; i < R; i++) {
                cin >> input;
                for (int j = 0; j < C; j++) {
                    board[i][j][k] = input[j];
                    if (board[i][j][k] == 'S') //시작점
                        start = make_tuple(i, j, k);
                }
            }
        }
        int result = bfs(start);
        if (result == -1)
            cout << "Trapped!\n";
        else
            cout << "Escaped in " << result << " minute(s).\n";
    }
}