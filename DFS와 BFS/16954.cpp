#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, int> pp;

vector<vector<vector<char>>> board;

int bfs() {
    queue<pair<pp, int>> q;
    q.push(make_pair(make_pair(7, 0), 0)); //초기좌표와 흐른 시간
    while (!q.empty()) {
        int row = q.front().first.first; //행
        int col = q.front().first.second; //열
        int status = q.front().second; //흐른 시간
        q.pop();

        if (((row == 0) && (col == 7)) || (status == 8)) //도착지점에 왔거나, 8초가 지나서 벽이 사라지면 종료
            return 1;
        vector<pp> candidate;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int nr = row + i;
                int nc = col + j;
                if ((nr >= 0) && (nr < 8) && (nc >= 0) && (nc < 8) && (board[nr][nc][status] == '.') && //범위내에 있는 빈공간
                    (board[nr][nc][status + 1] == '.')) //시간이 지나도 빈공간인지 확인
                    q.push(make_pair(make_pair(nr, nc), status + 1));
            }
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string input;

    board.assign(8, vector<vector<char>>(8, vector<char>(9, '.')));
    for (int i = 0; i < 8; i++) { //초기 상태
        cin >> input;
        for (int j = 0; j < 8; j++)
            board[i][j][0] = input[j];
    }
    for (int k = 1; k < 9; k++) { //시간 별 체스 판의 상태
        for (int i = 1; i < 8; i++) {
            for (int j = 0; j < 8; j++)
                board[i][j][k] = board[i - 1][j][k - 1];
        }
    }
    cout << bfs();
}