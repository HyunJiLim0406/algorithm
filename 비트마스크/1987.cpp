#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pp;

int R, C, result;
vector<vector<char>> board;
pp dir[4] = {{-1, 0}, //상
             {1,  0},  //하
             {0,  -1}, //좌
             {0,  1}}; //우

void dfs(int r, int c, int num, int move) {
    result = max(result, move); //최댓값 갱신
    for (int i = 0; i < 4; i++) {
        int nr = r + dir[i].first;
        int nc = c + dir[i].second;
        if ((nr >= 0) && (nr < R) && (nc >= 0) && (nc < C)) { //범위 내에 있으면
            int next_num = 1 << (board[nr][nc] - 'A'); //해당 알파벳을 비트로
            if ((num & next_num) == 0) //아직 방문하지 않은 알파벳이면 dfs
                dfs(nr, nc, num | next_num, move + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string input;

    cin >> R >> C;
    board.assign(R, vector<char>(C));
    for (int i = 0; i < R; i++) {
        cin >> input;
        for (int j = 0; j < C; j++)
            board[i][j] = input[j];
    }
    dfs(0, 0, 1 << (board[0][0] - 'A'), 1);
    cout << result;
}
