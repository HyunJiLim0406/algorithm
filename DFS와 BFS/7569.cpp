#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

struct pos {
    int x, y, z;
};

//범위 초과 때문에 상하좌우 한줄씩 추가
int matrix[102][102][102];
int N, M, H;
pos dir[6] = {{-1, 0,  0},  //상
              {1,  0,  0},   //하
              {0,  -1, 0},  //좌
              {0,  1,  0},   //우
              {0,  0,  1},   //위
              {0,  0,  -1}}; //아래

int bfs(vector<pos> starts) { //큐로 구현
    int day; //날짜 계산
    queue<pos> q;

    for (int i = 0; i < starts.size(); i++) //1인 토마토 먼저 넣어줌
        q.push({starts[i].x, starts[i].y, starts[i].z});
    while (!q.empty()) { //큐에 들어있는 모든 원소에 대해 가능한 방향 체크
        int x = q.front().x;
        int y = q.front().y;
        int z = q.front().z;
        day = matrix[x][y][z] - 1; //날짜 갱신
        q.pop();
        for (int i = 0; i < 6; i++) { //상하좌우 체크
            int next_x = x + dir[i].x;
            int next_y = y + dir[i].y;
            int next_z = z + dir[i].z;
            if (matrix[next_x][next_y][next_z] == 0) {
                matrix[next_x][next_y][next_z] = matrix[x][y][z] + 1; //matrix[next_x][next_y][next_z]를 오기 위해 몇 번 거쳐야 하는가?
                q.push({next_x, next_y, next_z});
            }
        }
    }
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= M; k++) {
                if (matrix[j][k][i] == 0) //익지 않은 토마토가 있는지 확인
                    return -1;
            }
        }
    }
    return day; //모두 익었다면 최소 날짜 리턴
}

int main() {
    vector<pos> starts;

    cin >> M >> N >> H;
    for (int i = 0; i < N + 2; i++) { //3차원 배열 초기화
        memset(matrix[i], -1, sizeof(int) * (M + 2));
        for (int j = 0; j < M + 2; j++)
            memset(matrix[i][j], -1, sizeof(int) * (H + 2));
    }
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= M; k++) {
                cin >> matrix[j][k][i];
                if (matrix[j][k][i] == 1) //1이라면 starts 벡터에 추가
                    starts.push_back({j, k, i});
            }
        }
    }
    cout << bfs(starts);
}