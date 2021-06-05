#include <iostream>
#include <vector>

using namespace std;

vector<int> dice(7, 0); //주사위
vector<vector<int>> board; //지도
pair<int, int> dir[4] = {{0,  1},  //동
                         {0,  -1}, //서
                         {-1, 0},  //북
                         {1,  0}}; //남

void rollDice(int d) { //윗면 : 1, 바닥 : 6을 유지하도록 주사위 이동
    vector<int> tmp = dice; //현재 주사위 복사
    switch (d) {
        case 0: //동
            dice[1] = tmp[4];
            dice[3] = tmp[1];
            dice[4] = tmp[6];
            dice[6] = tmp[3];
            break;
        case 1: //서
            dice[1] = tmp[3];
            dice[3] = tmp[6];
            dice[4] = tmp[1];
            dice[6] = tmp[4];
            break;
        case 2: //북
            dice[1] = tmp[5];
            dice[2] = tmp[1];
            dice[5] = tmp[6];
            dice[6] = tmp[2];
            break;
        case 3: //남
            dice[1] = tmp[2];
            dice[2] = tmp[6];
            dice[5] = tmp[1];
            dice[6] = tmp[5];
            break;
    }
}

int main() {
    int N, M, x, y, K, cmd;

    cin >> N >> M >> x >> y >> K;
    board.assign(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            cin >> board[i][j];
    }
    while (K--) {
        cin >> cmd;
        cmd--;
        int nx = x + dir[cmd].first;
        int ny = y + dir[cmd].second;
        if ((nx < 0) || (nx >= N) || (ny < 0) || (ny >= M)) //지도 밖을 벗어남
            continue;
        rollDice(cmd); //주사위 굴리기
        if (board[nx][ny] == 0) //해당 칸이 0일 때
            board[nx][ny] = dice[6];
        else { //해당 칸이 0이 아닐 때
            dice[6] = board[nx][ny];
            board[nx][ny] = 0;
        }
        cout << dice[1] << '\n'; //주사위의 윗면
        x = nx; //x 갱신
        y = ny; //y 갱신
    }
}