#include <iostream>
#include <vector>
#include <queue>

using namespace std;

string seat[5];
int pos[7];
int result = 0;
pair<int, int> dir[4] = {{-1, 0},  //상
                         {1,  0},  //하
                         {0,  -1}, //좌
                         {0,  1}}; //우

bool cntY() { //임도연 파의 수
    int cnt = 0;
    for (int i = 0; i < 7; i++) {
        if (seat[pos[i] / 5][pos[i] % 5] == 'Y')
            cnt++;
    }
    return cnt < 4;
}

bool isConnected() {
    vector<vector<bool>> marked(5, vector<bool>(5, false));
    for (int i = 1; i < 7; i++) //좌석 표시
        marked[pos[i] / 5][pos[i] % 5] = true;
    queue<pair<int, int>> q;
    q.push(make_pair(pos[0] / 5, pos[0] % 5)); //시작점
    int cnt = 1;
    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = r + dir[i].first;
            int nc = c + dir[i].second;
            if (nr < 0 || nr >= 5 || nc < 0 || nc >= 5 || !marked[nr][nc]) //범위 벗어나거나 같은 파가 아님
                continue;
            marked[nr][nc] = false; //방문 처리
            q.push(make_pair(nr, nc));
            cnt++;
        }
    }
    return cnt == 7; //7명 연결 확인
}

void backtracking(int idx, int cnt) {
    if (cnt == 7) {
        if (cntY() && isConnected())
            result++;
        return;
    }
    for (int i = idx + 1; i < 25; i++) {
        pos[cnt] = i;
        backtracking(i, cnt + 1);
    }
}

int main() {
    for (int i = 0; i < 5; i++)
        cin >> seat[i];
    backtracking(-1, 0);
    cout << result;
}