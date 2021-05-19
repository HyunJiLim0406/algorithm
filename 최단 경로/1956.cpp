#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int INF = 1e9;

vector<vector<int>> floydWarshall(vector<vector<int>> graph) { //플로이드-워셜
    int size = graph.size();
    for (int i = 1; i < size; i++) {
        for (int j = 1; j < size; j++) {
            for (int k = 1; k < size; k++)
                graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
        }
    }
    return graph;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> graph;
    int V, E, a, b, c;

    cin >> V >> E;
    graph.assign(V + 1, vector<int>(V + 1, INF));
    for (int i = 0; i < E; i++) {
        cin >> a >> b >> c;
        graph[a][b] = c;
    }
    for (int i = 1; i <= V; i++) //나 자신과의 거리는 0
        graph[i][i] = 0;
    graph = floydWarshall(graph);

    int min_dist = INF;
    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            if (i == j)
                continue;
            min_dist = min(min_dist, graph[i][j] + graph[j][i]); //i->j->i의 거리
        }
    }
    cout << ((min_dist == INF) ? -1 : min_dist);
}