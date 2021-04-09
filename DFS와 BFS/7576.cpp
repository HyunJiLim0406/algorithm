#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

//범위 초과 때문에 상하좌우 한줄씩 추가
int matrix[1002][1002];
int N, M;
pair<int, int> dir[4] = {{-1, 0},  //상
                         {1,  0},  //하
                         {0,  -1}, //좌
                         {0,  1}}; //우

int bfs(vector<pair<int, int>> starts) { //큐로 구현
    int day; //날짜 계산
    queue<pair<int, int>> q;

    for (int i = 0; i < starts.size(); i++) //1인 토마토 먼저 넣어줌
        q.push(make_pair(starts[i].first, starts[i].second));
    while (!q.empty()) { //큐에 들어있는 모든 원소에 대해 가능한 방향 체크
        int col = q.front().first;
        int row = q.front().second;
        day = matrix[col][row] - 1; //날짜 갱신
        q.pop();
        for (int i = 0; i < 4; i++) { //상하좌우 체크
            int next_col = col + dir[i].first;
            int next_row = row + dir[i].second;
            if (matrix[next_col][next_row] == 0) {
                matrix[next_col][next_row] = matrix[col][row] + 1; //matrix[next_col][next_row]를 오기 위해 몇 번 거쳐야 하는가?
                q.push(make_pair(next_col, next_row));
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (matrix[i][j] == 0) //익지 않은 토마토가 있는지 확인
                return -1;
        }
    }
    return day; //모두 익었다면 최소 날짜 리턴
}

int main() {
    vector<pair<int, int>> starts;

    cin >> M >> N;
    for (int i = 0; i < N + 2; i++) //2차원 배열 초기화
        memset(matrix[i], -1, sizeof(int) * (M + 2));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> matrix[i][j];
            if (matrix[i][j] == 1) //1이라면 starts 벡터에 추가
                starts.push_back(make_pair(i, j));
        }
    }
    cout << bfs(starts);
}