#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;
typedef pair<int, int> pp;

int cnt, N, M;
vector<vector<int>> board;
vector<int> idx_map;
pp dir[4] = {{-1, 0},  //상
             {1,  0},  //하
             {0,  -1}, //좌
             {0,  1}}; //우

void dfs(pp cur, int mark) { //빈 공간 인덱스 채우기
    cnt++;
    board[cur.first][cur.second] = mark;
    for (int i = 0; i < 4; i++) {
        int nr = cur.first + dir[i].first;
        int nc = cur.second + dir[i].second;
        if ((nr >= 0) && (nr < N) && (nc >= 0) && (nc < M) && (board[nr][nc] == 0)) //범위내에 있는 미방문 칸
            dfs(make_pair(nr, nc), mark);
    }
}

int cntBlock(pp pos) {
    set<int> s;
    int block_cnt = board[pos.first][pos.second];
    for (int i = 0; i < 4; i++) {
        int nr = pos.first + dir[i].first;
        int nc = pos.second + dir[i].second;
        if ((nr >= 0) && (nr < N) && (nc >= 0) && (nc < M) && (board[nr][nc] != 1)) //범위내에 있는 빈칸
            s.insert(board[nr][nc]); //인덱스 중복없이 저장
    }
    for (auto iter = s.begin(); iter != s.end(); iter++) //갈 수 있는 칸의 수
        block_cnt += idx_map[*iter];
    return block_cnt;
}

int main() {
    string input;

    cin >> N >> M;
    board.assign(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++) {
        cin >> input;
        for (int j = 0; j < M; j++)
            board[i][j] = input[j] - '0';
    }

    idx_map.push_back(0);
    idx_map.push_back(0);
    int idx = 2;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 0) { //모든 빈칸에 대해 그룹화 하고, 각 그룹의 칸 수를 map처럼 저장
                cnt = 0;
                dfs(make_pair(i, j), idx);
                idx_map.push_back(cnt);
                idx++;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 1) { //벽일때
                cout << cntBlock(make_pair(i, j)) % 10;
            } else //빈칸일때
                cout << 0;
        }
        cout << '\n';
    }
}