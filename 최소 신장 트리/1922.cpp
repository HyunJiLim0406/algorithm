#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;
typedef tuple<int, int, int> ti;

priority_queue<ti, vector<ti>, greater<>> pq;
vector<int> parent;

int findParent(int x) { //parent[x]가 음수가 될 때까지(root에 다다를 때까지) 재귀 함수 호출
    if (parent[x] < 0)
        return x;
    return parent[x] = findParent(parent[x]);
}

bool unionInput(int x, int y) {
    int x_p = findParent(x); //x의 부모
    int y_p = findParent(y); //y의 부모

    if (x_p == y_p) //이미 같은 집합, 이 간선 쓸 수 없음
        return false;
    if (parent[x_p] < parent[y_p]) { //x_p를 root로 하는 노드가 더 많으면 x_p -> y_p
        parent[x_p] += parent[y_p];
        parent[y_p] = x_p;
    } else { //y_p를 root로 하는 노드가 더 많으면 y_p -> x_p
        parent[y_p] += parent[x_p];
        parent[x_p] = y_p;
    }
    return true;
}

int kruskal(int V) {
    int cnt = 0, dist = 0;
    while (cnt != (V - 1)) {
        int cost = get<0>(pq.top()); //연결 비용
        int x = get<1>(pq.top());
        int y = get<2>(pq.top());
        pq.pop();

        if (unionInput(x, y)) { //연결 가능한 컴퓨터
            cnt++;
            dist += cost;
        }
    }
    return dist;
}

int main() {
    int N, M, a, b, c;

    cin >> N >> M;
    parent.assign(N + 1, -1);
    while (M--) {
        cin >> a >> b >> c;
        pq.push(make_tuple(c, a, b));
    }
    cout << kruskal(N);
}