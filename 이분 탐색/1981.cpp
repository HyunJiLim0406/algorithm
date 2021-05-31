#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, int> pp;

int N, max_value;
vector<vector<int>> board;
pp dir[4] = {{-1, 0},  //상
             {1,  0},  //하
             {0,  -1}, //좌
             {0,  1}}; //우

bool isBfs(int left, int right) { //bfs 가능한지 확인
    queue<pair<int, int>> q;
    vector<vector<bool>> visited;
    visited.assign(N, vector<bool>(N, false));
    if (board[0][0] < left || board[0][0] > right) //시작점 범위 체크
        return false;

    visited[0][0] = true;
    q.push(make_pair(0, 0));
    while (!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        if (row == (N - 1) && col == (N - 1)) //도착
            return true;
        for (int i = 0; i < 4; i++) {
            int nr = row + dir[i].first;
            int nc = col + dir[i].second;
            if ((nr < 0) || (nr >= N) || (nc < 0) || (nc >= N)) //인덱스 범위 체크
                continue;
            if (!visited[nr][nc] && (board[nr][nc] >= left) && (board[nr][nc] <= right)) { //방문 여부, 범위 체크
                visited[nr][nc] = true;
                q.push(make_pair(nr, nc));
            }
        }
    }
    return false;
}

bool isPromise(int mid) {
    for (int i = 0; i <= max_value - mid; i++) { //mid 차이가 나는 모든 숫자 쌍에 대해
        if (isBfs(i, i + mid))
            return true;
    }
    return false;
}

int lowerSearch(int left, int right) { //lower-bound
    while (left <= right) {
        int mid = (left + right) / 2;
        if (!isPromise(mid))
            left = mid + 1;
        else
            right = mid - 1;
    }
    return right + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    cin >> N;
    board.assign(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            max_value = max(max_value, board[i][j]);
        }
    }
    cout << lowerSearch(0, max_value);
}