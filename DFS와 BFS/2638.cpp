#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int N, M;
vector<vector<int>> board; //치즈 판
vector<pair<int, int>> cheese; //치즈들의 위치
pair<int, int> dir[4] = {{-1, 0},  //상
                         {1,  0},  //하
                         {0,  -1}, //좌
                         {0,  1}}; //우

void dfs(pair<int, int> cur) { //치즈 외부와 내부를 구분하는 dfs
    int row = cur.first;
    int col = cur.second;
    board[row][col] = -1; //외부 공기 처리
    for (int i = 0; i < 4; i++) {
        int nr = row + dir[i].first;
        int nc = col + dir[i].second;
        if ((nr >= 0) && (nr < N) && (nc >= 0) && (nc < M) && (board[nr][nc] == 0))
            dfs(make_pair(nr, nc));
    }
}

bool meltCheese() {
    bool all_melted = true; //더이상 녹일 치즈가 없는지 확인
    vector<pair<int, int>> will_melt; //이번에 녹일 치즈
    vector<pair<int, int>> will_dfs; //이번에 접근 가능해진 치즈 내부
    for (int i = 0; i < cheese.size(); i++) {
        int row = cheese[i].first;
        int col = cheese[i].second;
        if (board[row][col] != 1) //아직 안녹은 치즈일 때
            continue;
        all_melted = false;
        int cnt = 0; //외부 공기인 면
        bool is_air = false; //내부 공기 여부
        for (int j = 0; j < 4; j++) {
            int nr = row + dir[j].first;
            int nc = col + dir[j].second;
            if (board[nr][nc] == -1) //외부 공기
                cnt++;
            else if (board[nr][nc] == 0) //내부 공기
                is_air = true;
        }
        if (cnt >= 2) { //녹을 수 있는 치즈
            will_melt.push_back(make_pair(row, col));
            if (is_air) //이 치즈가 녹으면 치즈 내부에 공기가 통하게 됨
                will_dfs.push_back(make_pair(row, col));
        }
    }
    for (int i = 0; i < will_melt.size(); i++) //치즈를 녹임
        board[will_melt[i].first][will_melt[i].second] = -1;
    for (int i = 0; i < will_dfs.size(); i++) //외부 공기 유입
        dfs(make_pair(will_dfs[i].first, will_dfs[i].second));
    return all_melted; //true면 더이상 녹일 치즈가 없는 것
}

int main() {
    cin >> N >> M;
    board.assign(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j] == 1) //치즈의 위치 입력
                cheese.push_back(make_pair(i, j));
        }
    }
    dfs(make_pair(0, 0)); //초기 외부 공기 체크

    int cnt = 0; //전부 녹이는데 걸리는 시간
    while (!meltCheese())
        cnt++;
    cout << cnt;
}