#include <iostream>
#include <vector>

using namespace std;
const int DEEPEST = 18; //2^17 > 1e5

vector<int> depth; //각 정점의 깊이
vector<vector<int>> graph, dp;

void dfsDp(int cur, int d) {
    depth[cur] = d; //이번 정점의 깊이
    for (int i = 1; i < DEEPEST; i++) //부모 정점들. 1, 2, 4, 8...
        dp[cur][i] = dp[dp[cur][i - 1]][i - 1];
    for (int i = 0; i < graph[cur].size(); i++) {
        int node = graph[cur][i];
        if (!depth[node]) { //미방문 정점
            dp[node][0] = cur; //바로 위 부모
            dfsDp(node, d + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, a, b;

    cin >> N;
    depth.assign(N + 1, 0);
    graph.assign(N + 1, vector<int>(0));
    dp.assign(N + 1, vector<int>(DEEPEST, 0));
    for (int i = 0; i < N - 1; i++) { //양방향 그래프
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfsDp(1, 1); //root : 1, 깊이 : 1
    cin >> M;
    while (M--) {
        cin >> a >> b;
        if (depth[a] < depth[b]) //a 정점이 더 깊은 곳에 있도록
            swap(a, b);
        int pos = DEEPEST - 1; //맨 위에 있는 조상부터 내려오기
        while (depth[a] != depth[b]) { //두 정점의 깊이가 다르다면
            int next_depth = depth[dp[a][pos]];
            if (next_depth >= depth[b]) //b 정점보다 깊은 곳에 있다면 a를 변경
                a = dp[a][pos];
            pos--;
        }
        int result = a;
        if (a != b) { //a와 b가 다르다면
            for (int i = DEEPEST - 1; i >= 0; i--) {
                if (dp[a][i] != dp[b][i]) { //두 정점의 조상이 처음으로 달라지는 지점에서 갱신
                    a = dp[a][i];
                    b = dp[b][i];
                }
            }
            result = dp[a][0]; //바로 그 위가 최소 공통 조상
        }
        cout << result << '\n';
    }
}