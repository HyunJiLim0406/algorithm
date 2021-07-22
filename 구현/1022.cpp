#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

vector<vector<int>> board;
pair<int, int> dir[4] = {{0,  1},  //우
                         {-1, 0},  //상
                         {0,  -1}, //좌
                         {1,  0}}; //하

int fillBoard(int size, int r1, int c1, int r2, int c2) {
    bool is_moved = false;
    int num = 1, r = 0, c = 0, d = 0, len = 0, max_num = 0;
    while (len <= size) {
        if (r >= r1 && r <= r2 && c >= c1 && c <= c2) { //출력할 배열에 속한 숫자라면
            board[r - r1][c - c1] = num;
            max_num = max(max_num, num); //최댓값 갱신
        }
        num++;
        r += dir[d].first;
        c += dir[d].second;
        if ((r < -len) || (r > len) || (c < -len) || (c > len)) { //범위 벗어나면
            if (d == 0 && !is_moved) { //다음 칸으로 옮겨갈 수 있다면
                is_moved = true;
                len++;
            } else { //방향 바꾸기
                r = r - dir[d].first + dir[(d + 1) % 4].first;
                c = c - dir[d].second + dir[(d + 1) % 4].second;
                d = (d + 1) % 4;
                is_moved = false;
            }
        }
    }
    return max_num;
}

int digitCnt(int num) { //최댓값의 자리수
    int cnt = 0;
    while (num) {
        num /= 10;
        cnt++;
    }
    return cnt;
}

int main() {
    int r1, c1, r2, c2;

    cin >> r1 >> c1 >> r2 >> c2;
    int row = max(abs(r1), abs(r2));
    int col = max(abs(c1), abs(c2));
    int size = max(row, col); //모눈종이의 전체 크기
    board.assign(50, vector<int>(5));
    int num = fillBoard(size, r1, c1, r2, c2);
    for (int i = 0; i <= r2 - r1; i++) {
        for (int j = 0; j <= c2 - c1; j++)
            cout << setw(digitCnt(num)) << board[i][j] << ' ';
        cout << '\n';
    }
}