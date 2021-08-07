#include <iostream>
#include <vector>

using namespace std;

struct info {
    int r, c, d;
};

int A, B;
vector<vector<int>> board;
vector<info> robots;
pair<int, int> dir[4] = {{-1, 0},   //북
                         {0,  1},   //동
                         {1,  0},   //남
                         {0,  -1}}; //서

int findDir(char d) { //방향값 int로
    switch (d) {
        case 'N':
            return 0;
        case 'E':
            return 1;
        case 'S':
            return 2;
        case 'W':
            return 3;
        default:
            return -1;
    }
}

bool forwarding(int bot, int times) {
    int row = robots[bot].r;
    int col = robots[bot].c;
    int direction = robots[bot].d;

    board[row][col] = 0; //위치 지움
    for (int i = 0; i < times; i++) {
        row += dir[direction].first;
        col += dir[direction].second;
        if (row < 0 || row >= B || col < 0 || col >= A) { //범위 벗어남
            cout << "Robot " << bot << " crashes into the wall";
            return false;
        }
        if (board[row][col]) { //다른 로봇에 부딪힘
            cout << "Robot " << bot << " crashes into robot " << board[row][col];
            return false;
        }
    }
    board[row][col] = bot; //새로운 위치 표시
    robots[bot] = {row, col, direction}; //갱신
    return true;
}

void dirCommand(int bot, int times) {
    int direction = robots[bot].d;
    direction = (direction + times) % 4;
    robots[bot].d = direction;
}

int main() {
    int N, M, x, y, bot, times;
    char d_input, command;

    cin >> A >> B;
    board.assign(B, vector<int>(A));
    cin >> N >> M;
    robots.assign(N + 1, {0, 0, 0});
    for (int i = 1; i <= N; i++) {
        cin >> x >> y >> d_input;
        robots[i] = {B - y, x - 1, findDir(d_input)}; //행, 열, 방향
        board[robots[i].r][robots[i].c] = i; //지도에 표시
    }
    while (M--) {
        cin >> bot >> command >> times;
        switch (command) {
            case 'F': //앞으로 가기
                if (!forwarding(bot, times))
                    return 0;
                break;
            case 'L': //왼쪽 방향
                times %= 4;
                dirCommand(bot, 4 - times);
                break;
            case 'R': //오른쪽 방향
                times %= 4;
                dirCommand(bot, times);
                break;
        }
    }
    cout << "OK";
}