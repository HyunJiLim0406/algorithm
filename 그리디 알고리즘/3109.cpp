#include <iostream>
#include <vector>
#include <string>

using namespace std;

int R, C;
vector<vector<char>> board;

bool dfs(int r, int c) {
    if (c == C - 1) //도착
        return true;
    for (int i = r - 1; i <= r + 1; i++) { //위에서부터 순서대로
        if (i >= 0 && i < R && board[i][c + 1] == '.') { //범위내에 있고 파이프 연결 가능하면
            board[i][c + 1] = 'x'; //연결처리
            if (dfs(i, c + 1)) //성공한걸 확인하면 바로 리턴(그리디)
                return true;
        }
    }
    return false; //실패
}

int main() {
    int cnt = 0;
    string input;

    cin >> R >> C;
    board.assign(R, vector<char>(C));
    for (int i = 0; i < R; i++) {
        cin >> input;
        for (int j = 0; j < C; j++)
            board[i][j] = input[j];
    }
    for (int i = 0; i < R; i++) { //모든 행에 대해 시작
        if (dfs(i, 0))
            cnt++;
    }
    cout << cnt;
}