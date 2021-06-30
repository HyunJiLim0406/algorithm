#include <iostream>
#include <deque>
#include <vector>
#include <string>

using namespace std;
typedef pair<int, int> pp;

int n;
vector<vector<int>> board, dist;
pp dir[4] = {{-1, 0},  //상
             {1,  0},  //하
             {0,  -1}, //좌
             {0,  1}}; //우

int bfs() {
    deque<pp> dq;
    dist[0][0] = 0; //방을 바꾼 횟수
    dq.push_front(make_pair(0, 0));
    while (!dq.empty()) {
        int row = dq.front().first;
        int col = dq.front().second;
        dq.pop_front();

        if (row == (n - 1) && col == (n - 1)) //도착지점
            return dist[row][col];
        for (int i = 0; i < 4; i++) {
            int nr = row + dir[i].first;
            int nc = col + dir[i].second;
            if ((nr < 0) || (nr >= n) || (nc < 0) || (nc >= n) || dist[nr][nc] != -1) //범위를 벗어나거나 이미 방문
                continue;
            if (board[nr][nc]) { //흰 방
                dist[nr][nc] = dist[row][col];
                dq.push_front(make_pair(nr, nc)); //앞에 넣음
            } else { //검은 방
                dist[nr][nc] = dist[row][col] + 1;
                dq.emplace_back(nr, nc); //뒤에 넣음
            }
        }
    }
    return -1;
}

int main() {
    string input;

    cin >> n;
    board.assign(n, vector<int>(n));
    dist.assign(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++) {
        cin >> input;
        for (int j = 0; j < n; j++)
            board[i][j] = input[j] - '0';
    }
    cout << bfs();
}