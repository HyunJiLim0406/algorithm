#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, int> pp;

int N, M, D;
vector<vector<int>> board, archer;
pp dir[3] = {{0,  -1}, //좌
             {-1, 0},  //상
             {0,  1}}; //우

void archerPos() {
    for (int i = 0; i < (1 << M); i++) { //비트마스크
        vector<int> tmp;
        for (int j = 0; j < M; j++) {
            if (i & (1 << j))
                tmp.push_back(j);
        }
        if (tmp.size() == 3) //배치된 궁수가 3명이라면
            archer.push_back(tmp);
    }
}

void bfs(int r, int c) {
    vector<vector<int>> dist(N + 1, vector<int>(M, D));
    queue<pp> q;
    dist[r][c] = 0;
    q.push(make_pair(r, c));

    while (!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        if (dist[row][col] > D) //더이상 탐색할 필요 없음
            continue;
        if (board[row][col]) { //적이라면 공격 표시하고 break
            board[row][col] = 2;
            break;
        }
        for (int i = 0; i < 3; i++) {
            int nr = row + dir[i].first;
            int nc = col + dir[i].second;

            if ((nr >= 0) && (nr < N) && (nc >= 0) && (nc < M) && (dist[nr][nc] == D)) { //범위 내에 있는 미방문 지점
                dist[nr][nc] = dist[row][col] + 1; //거리 갱신
                q.push(make_pair(nr, nc));
            }
        }
    }
}

void target(int idx, int line) {
    for (int i = 0; i < 3; i++) //3명의 궁수가 공격하게 될 적의 수
        bfs(line, archer[idx][i]);
}

int shoot(int line) {
    int cnt = 0; //공격한 적의 수
    for (int i = 0; i < line; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 2) {
                board[i][j] = 0;
                cnt++;
            }
        }
    }
    return cnt;
}

void move(int line) { //적 이동(궁수 이동으로 구현)
    for (int i = 0; i < M; i++) {
        if (board[line][i]) //궁수 바로 앞에 있던 적들 삭제(성으로 들어옴)
            board[line][i] = 0;
    }
}

int main() {
    int result = 0;

    cin >> N >> M >> D;
    board.assign(N + 1, vector<int>(M, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            cin >> board[i][j];
    }
    archerPos(); //가능한 궁수 배치
    vector<vector<int>> tmp = board;
    for (int i = 0; i < archer.size(); i++) {
        board = tmp; //복사
        int line = N, attack = 0;
        while (line) { //적들이 성에 전부 들어오지 않았다면
            target(i, line); //공격하게 될 적
            attack += shoot(line); //공격
            move(line - 1); //적 이동
            line--;
        }
        result = max(result, attack); //최댓값 갱신
    }
    cout << result;
}