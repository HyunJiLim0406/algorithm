#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;
typedef pair<int, int> pp;

priority_queue<pair<int, pp>, vector<pair<int, pp>>, greater<pair<int, pp>>> pq; //min-heap
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

int kruskalMst(int V) {
    int cnt = 0, weight = 0;

    while (cnt != (V - 1)) { //사용한 간선이 V-1개이면 break
        int dist = pq.top().first; //간선의 weight
        int x = pq.top().second.first;
        int y = pq.top().second.second;

        pq.pop();
        if (unionInput(x, y)) { //x, y를 유니온할 수 있다면
            cnt++;
            weight += dist;
        }
    }
    return weight; //그래프의 가중치 합
}

int main() {
    int V, E, A, B, C;

    cin >> V >> E;
    parent.assign(V + 1, -1);
    for (int i = 0; i < E; i++) {
        cin >> A >> B >> C;
        pq.push(make_pair(C, make_pair(A, B)));
    }
    cout << kruskalMst(V);
}