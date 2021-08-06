#include <iostream>
#include <vector>

using namespace std;

int N, result;
vector<vector<bool>> graph;
int list[3];

bool isPromise() {
    for (int i = 0; i < 2; i++) {
        for (int j = i + 1; j < 3; j++) {
            if (graph[list[i]][list[j]]) //조합 확인
                return false;
        }
    }
    return true;
}

void backtracking(int idx, int cnt) {
    if (cnt == 3) { //3개 고르기
        if (isPromise())
            result++;
        return;
    }
    for (int i = idx + 1; i <= N; i++) {
        list[cnt] = i;
        backtracking(i, cnt + 1);
    }
}

int main() {
    int M, a, b;

    cin >> N >> M;
    graph.assign(N + 1, vector<bool>(N + 1));
    while (M--) {
        cin >> a >> b;
        graph[a][b] = graph[b][a] = true;
    }
    backtracking(0, 0);
    cout << result;
}