#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> pp;

int N, L, R;
vector<vector<int>> board, idx_table; //지도, 지도 인덱싱
vector<int> idx; //인덱스별 인구 수
pp dir[4] = {{-1, 0},  //상
             {1,  0},  //하
             {0,  -1}, //좌
             {0,  1}}; //우

pp dfs(pp cur, int mark) {
    int num = board[cur.first][cur.second], cnt = 1; //연합의 총 인구 수, 연합에 속한 나라 수
    idx_table[cur.first][cur.second] = mark; //인덱싱
    for (int i = 0; i < 4; i++) {
        int nr = cur.first + dir[i].first;
        int nc = cur.second + dir[i].second;
        if ((nr < 0) || (nr >= N) || (nc < 0) || (nc >= N) || (idx_table[nr][nc] != -1)) //범위 초과 or 이미 인덱싱됨
            continue;
        int diff = abs(board[cur.first][cur.second] - board[nr][nc]); //두 국가의 인구 차이
        if (diff >= L && diff <= R) { //범위에 들어왔을 때
            pp tmp = dfs(make_pair(nr, nc), mark); //dfs 결과 저장
            num += tmp.first; //총 인구 수 갱신
            cnt += tmp.second; //총 나라 수 갱신
        }
    }
    return make_pair(num, cnt);
}

int fillIdx() {
    int mark = 0;
    idx_table.assign(N, vector<int>(N, -1)); //인덱싱 초기화
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (idx_table[i][j] == -1) { //인덱스가 없는 국가
                pp dfs_result = dfs(make_pair(i, j), mark);
                idx[mark++] = dfs_result.first / dfs_result.second; //연합의 인구수에서 연합에 속한 나라의 수를 나눈 값 저장
            }
        }
    }
    return mark;
}

void movePeople() { //인구 이동
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            board[i][j] = idx[idx_table[i][j]];
    }
}

int main() {
    cin >> N >> L >> R;
    board.assign(N, vector<int>(N, 0));
    idx.assign(N * N, 0);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cin >> board[i][j];
    }

    int result = 0;
    while (true) {
        int mark = fillIdx(); //총 연합의 수
        if (mark == (N * N)) //합쳐진 나라가 없음
            break;
        movePeople(); //인구 이동
        result++; //이동 횟수 증가
    }
    cout << result;
}