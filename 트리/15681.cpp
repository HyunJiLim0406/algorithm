#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<int> sub_cnt;

int makeTree(int cur) {
    if (sub_cnt[cur] != -1)
        return sub_cnt[cur];

    sub_cnt[cur] = 0;
    int node = 1;
    for (int i = 0; i < graph[cur].size(); i++) //서브트리 정점의 수
        node += makeTree(graph[cur][i]);
    return sub_cnt[cur] = node;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, r, q, u, v, input;

    cin >> n >> r >> q;
    graph.assign(n + 1, vector<int>(0));
    sub_cnt.assign(n + 1, -1);

    while (--n) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    makeTree(r); //루트에 대해 트리 생성하며 서브 트리의 정점 수 계산
    while (q--) {
        cin >> input;
        cout << sub_cnt[input] << '\n';
    }
}