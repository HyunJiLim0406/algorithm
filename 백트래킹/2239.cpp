#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

vector<vector<int>> board;
vector<pair<int, int>> zeros;
bool isFound;

bool isPromise(pair<int, int> pos, int num) {
    int row = pos.first;
    int col = pos.second;
    int r_sector = row / 3;
    int c_sector = col / 3;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if ((i == row) && (j == col))
                continue;
            if (((i == row) || (j == col)) && (board[i][j] == num)) //같은 행 또는 열에 이미 숫자가 있음
                return false;
            else if (((i / 3) == r_sector) && ((j / 3) == c_sector) && (board[i][j] == num)) //같은 구역에 이미 숫자가 있음
                return false;
        }
    }
    return true;
}

void backtracking(int cnt) {
    if (cnt == zeros.size()) { //전부 찾으면 출력하고 종료
        isFound = true;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++)
                cout << board[i][j];
            cout << '\n';
        }
        return;
    }
    for (int i = 1; i <= 9 && !isFound; i++) { //1~9까지 숫자 넣어보고 가능한지 확인
        if (isPromise(zeros[cnt], i)) { //이 숫자 들어갈 수 있으면 재귀 호출
            board[zeros[cnt].first][zeros[cnt].second] = i; //visited 처리
            backtracking(cnt + 1);
            board[zeros[cnt].first][zeros[cnt].second] = 0; //unvisited 처리
        }
    }
}

int main() {
    string input;
    board.assign(9, vector<int>(9, 0));
    for (int i = 0; i < 9; i++) {
        cin >> input;
        for (int j = 0; j < 9; j++) {
            board[i][j] = input[j] - '0';
            if (board[i][j] == 0) //0의 위치 저장
                zeros.push_back(make_pair(i, j));
        }
    }
    backtracking(0);
}