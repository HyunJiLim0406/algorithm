#include <iostream>
#include <vector>

using namespace std;

int n, tot_sand = 0;
vector<vector<int>> board;
pair<int, int> dir[4] = {{0,  -1},
                         {1,  0},
                         {0,  1},
                         {-1, 0}};

int move(int row, int col, int sand) {
    if (row < 0 || row >= n || col < 0 || col >= n) //범위 벗어남
        tot_sand += sand;
    else //모래 이동
        board[row][col] += sand;
    return sand;
}

//각 방향으로 모래 뿌리기
int moveSand(int row, int col, int d, int sand) {
    int ans = 0;
    ans += move(row + (dir[d].first * 2), col + (dir[d].second * 2), (int)(sand * 0.05));
    ans += move(row + dir[d].first + dir[(d + 1) % 4].first, col + dir[d].second + dir[(d + 1) % 4].second, (int)(sand * 0.1));
    ans += move(row + dir[d].first + dir[(d + 3) % 4].first, col + dir[d].second + dir[(d + 3) % 4].second, (int)(sand * 0.1));
    ans += move(row + dir[(d + 1) % 4].first, col + dir[(d + 1) % 4].second, (int)(sand * 0.07));
    ans += move(row + dir[(d + 3) % 4].first, col + dir[(d + 3) % 4].second, (int)(sand * 0.07));
    ans += move(row + (dir[(d + 1) % 4].first * 2), col + (dir[(d + 1) % 4].second * 2), (int)(sand * 0.02));
    ans += move(row + (dir[(d + 3) % 4].first * 2), col + (dir[(d + 3) % 4].second * 2), (int)(sand * 0.02));
    ans += move(row + dir[(d + 2) % 4].first + dir[(d + 1) % 4].first,
                col + dir[(d + 2) % 4].second + dir[(d + 1) % 4].second, (int)(sand * 0.01));
    ans += move(row + dir[(d + 2) % 4].first + dir[(d + 3) % 4].first,
                col + dir[(d + 2) % 4].second + dir[(d + 3) % 4].second, (int)(sand * 0.01));
    return ans;
}

void tornado() {
    int len = 1, cur_len = 0, cnt = 0, d = 0;
    int row = n / 2, col = n / 2; //시작점
    while (row || col) { //(0, 0)에 도달하면 break
        //y
        row += dir[d].first;
        col += dir[d].second;

        board[row][col] -= moveSand(row, col, d, board[row][col]); //모래 이동
        board[row][col] -= move(row + dir[d].first, col + dir[d].second, board[row][col]); //a 모래 이동

        cur_len++;
        //방향 전환
        if (cur_len == len) {
            cur_len = 0;
            d = (d + 1) % 4;
            cnt++;
            if (cnt == 2) { //길이 증가
                cnt = 0;
                len++;
            }
        }
    }
}

int main() {
    cin >> n;
    board.assign(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> board[i][j];
    }
    tornado();
    cout << tot_sand;
}