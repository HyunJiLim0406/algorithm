#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;
typedef pair<int, int> pp;

priority_queue<pair<int, pp>, vector<pair<int, pp>>, greater<pair<int, pp>>> pq; //min-heap
vector<int> parent;
vector<vector<pp>> planet; //행성 정보

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
    int N, x, y, z;

    cin >> N;
    parent.assign(N, -1);
    planet.assign(3, vector<pp>(N, make_pair(0, 0)));
    for (int i = 0; i < N; i++) { //x, y, z 좌표와 기존의 인덱스 저장
        cin >> x >> y >> z;
        planet[0][i] = make_pair(x, i);
        planet[1][i] = make_pair(y, i);
        planet[2][i] = make_pair(z, i);
    }
    for (int i = 0; i < 3; i++) {
        sort(planet[i].begin(), planet[i].end()); //x, y, z에 대해 정렬
        for (int j = 0; j < planet[i].size() - 1; j++) { //x, y, z에 대해 인접한 행성끼리만 거리 구하기
            int distance = planet[i][j + 1].first - planet[i][j].first;
            pq.push(make_pair(distance, make_pair(planet[i][j + 1].second, planet[i][j].second)));
        }
    }
    cout << kruskalMst(N);
}