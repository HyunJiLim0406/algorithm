#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> board;

void fillStar(int start, int end) {
    for (int i = start; i <= end; i++) {
        for (int j = start; j <= end; j++) {
            if (i == start || i == end || j == start || j == end) //테두리에 별 찍기
                board[i][j] = '*';
        }
    }
}

int main() {
    int N;

    cin >> N;
    board.assign(4 * N - 3, vector<char>(4 * N - 3, ' '));
    int idx = 0;
    while (N--) { //각 사각형 반복문으로 만들기
        int len = 4 * N;
        fillStar(idx, idx + len);
        idx += 2;
    }
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++)
            cout << board[i][j];
        cout << '\n';
    }
}