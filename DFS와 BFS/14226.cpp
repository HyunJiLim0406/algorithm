#include <iostream>
#include <queue>

using namespace std;

const int MAX = 1001;

struct emoji {
    int num, time, pasted;
};

int S;
bool visited[MAX][MAX]; //visited[num][pasted]

int bfs() {
    queue<emoji> q;

    q.push({1, 0, 0});
    visited[1][0] = true;
    while (!q.empty()) {
        int c_num = q.front().num; //이모티콘 수
        int c_time = q.front().time; //걸린 시간
        int c_pasted = q.front().pasted; //클립보드에 복사된 이모티콘 수
        q.pop();
        if (c_num == S) //종료 조건
            return c_time;

        if ((c_num > 0) && !visited[c_num][c_num]) { //클립보드 복사
            visited[c_num][c_num] = true;
            q.push({c_num, c_time + 1, c_num});
        }
        if (((c_num + c_pasted) < MAX) && !visited[c_num + c_pasted][c_pasted]) { //붙여넣기
            visited[c_num + c_pasted][c_pasted] = true;
            q.push({c_num + c_pasted, c_time + 1, c_pasted});
        }
        if ((c_num > 0) && !visited[c_num - 1][c_pasted]) { //삭제
            visited[c_num - 1][c_pasted] = true;
            q.push({c_num - 1, c_time + 1, c_pasted});
        }
    }
    return 0;
}

int main() {
    cin >> S;
    cout << bfs();
}