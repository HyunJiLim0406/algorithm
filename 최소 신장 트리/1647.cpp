#include <iostream>
#include <queue>
#include <vector>

using namespace std;
typedef pair<int, int> pp;

vector<int> parent;
priority_queue<pair<int, pp>, vector<pair<int, pp>>, greater<pair<int, pp>>> pq; //min-heap

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

int splitKruskal(int v) {
    int weight = 0, cnt = 0;

    while (cnt != (v - 2)) { //마을을 분리하니까 v-2까지만 찾아도 됨
        int w = pq.top().first; //간선의 weight
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        if (unionInput(x, y)) { //x, y를 유니온할 수 있다면
            weight += w;
            cnt++;
        }
    }
    return weight;
}

int main() {
    int N, M, A, B, C;

    cin >> N >> M;
    parent.assign(N + 1, -1);
    for (int i = 0; i < M; i++) {
        cin >> A >> B >> C;
        pq.push(make_pair(C, make_pair(A, B)));
    }
    cout << splitKruskal(N);
}