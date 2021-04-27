#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> pp;

vector<vector<pp>> graph;
vector<pp> status; //first=거리, second=방문여부
int max_diameter, node;

void dfs(int cur) {
    for (int i = 0; i < graph[cur].size(); i++) {
        int dest = graph[cur][i].first;
        if (status[dest].second == 0) { //미방문 정점
            status[dest].second = 1; //방문 처리
            status[dest].first = status[cur].first + graph[cur][i].second; //거리 갱신
            if (max_diameter < status[dest].first) { //최대 지름보다 크다면 갱신
                max_diameter = status[dest].first;
                node = dest;
            }
            dfs(dest); //dfs 호출
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, p, c, w;

    cin >> n;
    graph.assign(n + 1, vector<pp>(0));
    for (int i = 1; i < n; i++) {
        cin >> p >> c >> w;
        graph[p].push_back(make_pair(c, w));
        graph[c].push_back(make_pair(p, w));
    }
    status.assign(n + 1, make_pair(0, 0)); //1에 대한 dfs를 한 뒤, 1과 제일 먼 node를 구함
    status[1].second = 1; //방문처리
    dfs(1);

    status.assign(n + 1, make_pair(0, 0)); //node에 대한 dfs
    status[node].second = 1; //방문처리
    dfs(node);

    cout << max_diameter << '\n';
}