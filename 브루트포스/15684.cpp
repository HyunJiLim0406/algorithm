#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int result = 4, N, H;
vector<vector<bool>> visited;

bool isPromise() {
    for (int i = 0; i < N; i++) {
        int cur = i; //사다리를 시작할 인덱스
        for (int j = 0; j < H; j++) {
            if (visited[cur][j]) //오른쪽으로 이동
                cur++;
            else if ((cur > 0) && visited[cur - 1][j]) //왼쪽으로 이동
                cur--;
        }
        if (cur != i) //사다리 실패
            return false;
    }
    return true;
}

void backtracking(int cnt, int idx) {
    if (cnt >= result) //최솟값 이상은 탐색하지 않음
        return;
    if (isPromise()) { //사다리 됐는지 확인
        result = cnt;
        return;
    }
    for (int i = idx; i < N - 1; i++) {
        for (int j = 0; j < H; j++) {
            if (visited[i][j] || (i > 0 && visited[i - 1][j]) || visited[i + 1][j]) //해당 위치와 좌우 확인
                continue;
            visited[i][j] = true; //visited 처리
            backtracking(cnt + 1, i);
            visited[i][j] = false; //unvisited 처리
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int M, a, b;

    cin >> N >> M >> H;
    visited.assign(N, vector<bool>(H, false));
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        visited[b - 1][a - 1] = true; //방문 처리
    }
    backtracking(0, 0);
    cout << ((result == 4) ? -1 : result);
}