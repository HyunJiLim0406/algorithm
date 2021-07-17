#include <iostream>
#include <vector>

using namespace std;

double percentage;
int N, dir_percent[4];
bool board[29][29];
pair<int, int> dir[4] = {{0,  1},  //동
                         {0,  -1}, //서
                         {1,  0},  //남
                         {-1, 0}}; //북

void backtracking(int r, int c, int cnt, double p) {
    if (cnt == N) { //끝까지 이동
        percentage += p;
        return;
    }
    for (int i = 0; i < 4; i++) {
        int nr = r + dir[i].first;
        int nc = c + dir[i].second;
        if (!board[nr][nc]) { //미방문 정점
            board[nr][nc] = true; //방문 처리
            backtracking(nr, nc, cnt + 1, p * (dir_percent[i] * 0.01));
            board[nr][nc] = false; //방문 해제
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < 4; i++)
        cin >> dir_percent[i];
    board[14][14] = true; //시작점 방문 처리
    backtracking(14, 14, 0, 1.0);
    cout << fixed;
    cout.precision(10);
    cout << percentage;
}