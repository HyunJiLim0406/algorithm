#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;
typedef tuple<int, int, int> tp;

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

long long kruskal(int n, priority_queue<tp, vector<tp>, greater<>> &pq) {
    long long result = 0;
    int cnt = 0;
    while (cnt != n - 1 && !pq.empty()) {
        int x = get<1>(pq.top());
        int y = get<2>(pq.top());
        int dist = get<0>(pq.top());
        pq.pop();

        if (unionInput(x, y)) { //연결 가능
            cnt++;
            result += dist;
        }
    }
    if (cnt < n - 1)
        return -1;
    return result;
}


int main() {
    int n, m, a, b, c;
    long long tot_cost = 0;

    cin >> n >> m;
    priority_queue<tp, vector<tp>, greater<>> pq;
    parent.assign(n + 1, -1);
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        pq.push({c, a, b});
        tot_cost += c;
    }

    long long ans = kruskal(n, pq);
    if (ans == -1)
        cout << ans;
    else
        cout << tot_cost - ans;
}