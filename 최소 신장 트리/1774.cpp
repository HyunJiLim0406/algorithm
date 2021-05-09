#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <cmath>

using namespace std;
typedef pair<int, int> pp;

int v_cnt; //사용한 간선의 수
vector<pair<double, double>> pos; //각 입력의 x, y 좌표
priority_queue<pair<double, pp>, vector<pair<double, pp>>, greater<pair<double, pp>>> pq; //min-heap
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

double kruskalMst(int V) {
    double weight = 0;

    while (v_cnt != (V - 1)) { //사용한 간선이 V-1개이면 break
        double dist = pq.top().first; //간선의 weight
        int x = pq.top().second.first;
        int y = pq.top().second.second;

        pq.pop();
        if (unionInput(x, y)) { //x, y를 유니온할 수 있다면
            v_cnt++;
            weight += dist;
        }
    }
    return weight; //그래프의 가중치 합
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, x, y;
    double a, b;

    cin >> n >> m;
    parent.assign(n + 1, -1);
    pos.push_back(make_pair(-1, -1));
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        pos.push_back(make_pair(a, b));
    }
    for (int i = 1; i <= n - 1; i++) { //모든 입력들 사이의 거리를 구해서 min-heap에 투입
        for (int j = i + 1; j <= n; j++) {
            double distance = pow((pos[i].first - pos[j].first), 2) + pow((pos[i].second - pos[j].second), 2);
            pq.push(make_pair(sqrt(distance), make_pair(i, j)));
        }
    }
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        if (unionInput(x, y)) //유니온 했다면 v_cnt 증가
            v_cnt++;
    }
    cout << fixed;
    cout.precision(2);
    cout << kruskalMst(n);
}