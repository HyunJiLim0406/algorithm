#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int visited[1001][1001];

int bfs(vector<int> stone) {
    queue<vector<int>> q;
    q.push(stone);
    while (!q.empty()) {
        vector<int> cur = q.front();
        q.pop();

        if ((cur[0] == cur[1]) && (cur[0] == cur[2])) //종료조건
            return 1;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == j)
                    continue;
                if ((cur[i] < cur[j]) && (visited[cur[i]][cur[j]] == 0)) { //대소관계이고, 이 둘의 조합을 탐색한 적 없다면
                    visited[cur[i]][cur[j]] = 1; //방문 처리
                    int saved_i = cur[i], saved_j = cur[j]; //원래의 값 저장
                    cur[i] = saved_i * 2; //작은 수 갱신
                    cur[j] = saved_j - saved_i; //큰 수 갱신
                    q.push(cur); //큐에 삽입
                    cur[i] = saved_i; //작은 수 복원
                    cur[j] = saved_j; //큰 수 복원
                }
            }
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> stone;
    int sum = 0;

    stone.assign(3, 0);
    for (int i = 0; i < 3; i++) {
        cin >> stone[i];
        sum += stone[i];
    }
    if (sum % 3 != 0) { //3으로 나누어 떨어지지 않으면 탐색할 필요 없음
        cout << 0;
        return 0;
    }
    cout << bfs(stone);
}