#include <iostream>
#include <vector>

using namespace std;

vector<int> depth, parent;
vector<vector<int>> graph;

void dfsDp(int cur, int p) {
    depth[cur] = depth[p] + 1; //깊이
    parent[cur] = p; //부모
    for (int i = 0; i < graph[cur].size(); i++) {
        if (!depth[graph[cur][i]]) //미방문 정점
            dfsDp(graph[cur][i], cur);
    }
}

int main() {
    int N, M, a, b;

    cin >> N;
    depth.assign(N + 1, 0);
    parent.assign(N + 1, -1);
    graph.assign(N + 1, vector<int>(0));
    for (int i = 0; i < N - 1; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfsDp(1, 0);
    cin >> M;
    while (M--) {
        cin >> a >> b;
        if (depth[a] < depth[b]) //a의 깊이가 더 깊도록
            swap(a, b);
        while (depth[a] != depth[b]) //a 올리면서 깊이가 같아지도록
            a = parent[a];
        while (a != b) { //a와 b가 같아질 때까지 부모로 올라감
            a = parent[a];
            b = parent[b];
        }
        cout << a << '\n'; //출력
    }
}