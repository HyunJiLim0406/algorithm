#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

vector<bool> check;
vector<int> parent;

int findParent(int node) { //parent[node]가 음수가 될 때까지(root에 다다를 때까지) 재귀 함수 호출
    if (parent[node] < 0)
        return node;
    return parent[node] = findParent(parent[node]);
}

bool unionInput(int x, int y) {
    int xp = findParent(x); //x의 부모
    int yp = findParent(y); //y의 부모

    if (xp == yp) //이미 같은 집합, 이 간선 쓸 수 없음
        return false;
    if (parent[xp] < parent[yp]) {
        parent[xp] += parent[yp];
        parent[yp] = xp;
    } else {
        parent[yp] += parent[xp];
        parent[xp] = yp;
    }
    return true;
}

int kruskal(int n, vector<tuple<int, int, int>> &edges) {
    int idx = 0, cnt = 0, result = 0;
    while (cnt != n - 1 && idx < edges.size()) {
        if (check[idx]) { //사용할 수 없는 간선
            idx++;
            continue;
        }
        int x = get<1>(edges[idx]);
        int y = get<2>(edges[idx]);
        int dist = get<0>(edges[idx]);

        if (unionInput(x, y)) {
            if (cnt == 0) //가중치가 가장 작은 간선
                check[idx] = true;
            cnt++;
            result += dist;
        }
        idx++;
    }
    if (cnt < n - 1)
        return 0;
    return result;
}

int main() {
    int n, m, k, x, y;

    cin >> n >> m >> k;
    vector<tuple<int, int, int>> edges;
    check.assign(m, false);
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        edges.emplace_back(i, x, y);
    }
    sort(edges.begin(), edges.end()); //정렬

    bool flag = false;
    while (k--) {
        if (flag) { //이미 mst를 만들 수 없음
            cout << 0 << ' ';
            continue;
        }
        parent.assign(n+1, -1); //초기화
        int ans = kruskal(n, edges);
        if (ans == 0)
            flag = true;
        cout << ans << ' ';
    }
}