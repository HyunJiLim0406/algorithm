#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> cost, parent;

int findParent(int node) {
    if (parent[node] < 0)
        return node;
    return parent[node] = findParent(parent[node]);
}

void unionInput(int x, int y) {
    int xp = findParent(x);
    int yp = findParent(y);

    if (xp == yp) //부모가 같을 때
        return;
    if (cost[xp] < cost[yp]) //비용이 더 작은 노드가 부모 노드가 되도록
        parent[yp] = xp;
    else
        parent[xp] = yp;
}

int main() {
    int N, M, k, v, w, result = 0;
    set<int> s;

    cin >> N >> M >> k;
    cost.assign(N + 1, 0);
    parent.assign(N + 1, -1); //초기화
    for (int i = 1; i <= N; i++)
        cin >> cost[i];
    while (M--) {
        cin >> v >> w;
        unionInput(v, w);
    }
    for (int i = 1; i <= N; i++) {
        if (parent[i] == -1) //root라면 비용 더하기
            result += cost[i];
    }
    if (result <= k)
        cout << result;
    else
        cout << "Oh no";
}