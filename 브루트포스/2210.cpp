#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

set<string> result; //중복 제거
vector<vector<string>> board(5, vector<string>(5));
pair<int, int> dir[4] = {{-1, 0},  //상
                         {1,  0},  //하
                         {0,  -1}, //좌
                         {0,  1}}; //우

void backtracking(string cur, int r, int c) {
    if (cur.length() == 6) { //5번 이동
        result.insert(cur);
        return;
    }
    for (int i = 0; i < 4; i++) {
        int nr = r + dir[i].first;
        int nc = c + dir[i].second;
        if ((nr >= 0) && (nr < 5) && (nc >= 0) && (nc < 5)) //범위 내에 있다면
            backtracking(cur + board[nr][nc], nr, nc);
    }
}

int main() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++)
            cin >> board[i][j];
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++)
            backtracking(board[i][j], i, j); //모든 정점을 시작으로 하는 수들
    }
    cout << result.size();
}