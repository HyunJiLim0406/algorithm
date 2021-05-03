#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> ordered;
vector<int> parent;
vector<vector<int>> graph;

void markParent() { //bfs 부모찾기
    queue<int> q;
    parent[0] = -1;
    q.push(0);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < graph[cur].size(); i++) {
            if (parent[graph[cur][i]] == -2) {
                parent[graph[cur][i]] = cur;
                q.push(graph[cur][i]);
            }
        }
    }
}

bool possibleRoute(int n, int start) {
    queue<int> q;
    vector<bool> visited;
    visited.assign(n, false);
    q.push(start);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        vector<int> tmp;
        tmp.push_back(parent[cur]); //부모
        tmp.push_back(ordered[cur]); //선행 노드
        for (int i = 0; i < 2; i++) {
            if ((tmp[i] != -1) && !visited[tmp[i]]) { //존재하는 미방문 노드
                if (tmp[i] == start) //시작점과 같다면 사이클
                    return false;
                visited[tmp[i]] = true; //방문 처리
                q.push(tmp[i]);
            }
        }
    }
    return true;
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    ordered.assign(n, -1); //먼저 방문해야 하는게 있나
    parent.assign(n, -2); //부모 노드
    graph.assign(n, vector<int>(0));
    for (int i = 0; i < path.size(); i++) { //양방향 그래프
        graph[path[i][0]].push_back(path[i][1]);
        graph[path[i][1]].push_back(path[i][0]);
    }
    for (int i = 0; i < order.size(); i++) //방문관계
        ordered[order[i][1]] = order[i][0];

    markParent(); //부모 입력
    for (int i = 0; i < order.size(); i++) { //이 경로 가능한가?
        if (!possibleRoute(n, order[i][1]))
            return false;
    }
    return true;
}

//효율성 통과 실패
int main() {
    cout << solution(9, {{0, 1},
                         {0, 3},
                         {0, 7},
                         {8, 1},
                         {3, 6},
                         {1, 2},
                         {4, 7},
                         {7, 5}}, {{8, 5},
                                   {6, 7},
                                   {4, 1}}) << '\n';
    cout << solution(9, {{0, 1},
                         {0, 3},
                         {0, 7},
                         {8, 1},
                         {3, 6},
                         {1, 2},
                         {4, 7},
                         {7, 5}}, {{5, 2},
                                   {4, 1}}) << '\n';
    cout << solution(9, {{0, 1},
                         {0, 3},
                         {0, 7},
                         {8, 1},
                         {3, 6},
                         {1, 2},
                         {4, 7},
                         {7, 5}}, {{8, 7},
                                   {6, 5},
                                   {4, 1}}) << '\n';
}