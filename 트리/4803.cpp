#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
int tree_cnt;
bool isTree;

void dfs(int cur, int source) {
    if (visited[cur]) { //사이클 형성
        isTree = false;
        return;
    }
    visited[cur] = true;
    for (int i = 0; i < graph[cur].size(); i++) { //단방향 탐색
        if (graph[cur][i] != source) //1->2로 탐색했었다면 2->1은 탐색하지 않도록
            dfs(graph[cur][i], cur);
    }
}

void printResult(int num, int cnt) { //출력
    cout << "Case " << num;
    switch (cnt) {
        case 0:
            cout << ": No trees.\n";
            break;
        case 1:
            cout << ": There is one tree.\n";
            break;
        default:
            cout << ": A forest of " << cnt << " trees.\n";
    }
}

int main() {
    int a, b, c, d, tc = 0;

    while (true) {
        tc++;
        cin >> a >> b;
        if ((a == 0) && (b == 0))
            break;
        graph.assign(a + 1, vector<int>(0));
        visited.assign(a + 1, false);
        for (int i = 0; i < b; i++) {
            cin >> c >> d;
            graph[c].push_back(d);
            graph[d].push_back(c);
        }

        tree_cnt = 0;
        for (int i = 1; i <= a; i++) {
            if (!visited[i]) {
                isTree = true;
                dfs(i, -1);
                if (isTree) //사이클이 없었으면 트리임임
                    tree_cnt++;
            }
        }
        printResult(tc, tree_cnt);
    }
}