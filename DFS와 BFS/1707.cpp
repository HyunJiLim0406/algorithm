#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>> graph; //배열에 넣으면 메모리 초과라 벡터 사용
vector<int> color; //0: 방문 하지 않음, 1: 1로 색칠, 2: 2로 색칠
int V, E;

int getColor(int color) { //무슨 색으로 칠해야 하는지 알려주는 함수
    if (color == 1)
        return 2;
    return 1;
}

void bfs() {
    int cur = 1; //1번 정점부터 시작
    queue<int> q;

    color[cur] = 1;
    q.push(cur);
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        for (int i = 0; i < graph[cur].size(); i++) {
            if (color[graph[cur][i]] == 0) { //방문한 적 없는 정점이라면 color[cur]과 다른 색으로 칠해서 방문 표시
                color[graph[cur][i]] = getColor(color[cur]);
                q.push(graph[cur][i]);
            } else if (color[graph[cur][i]] == color[cur]) { //연결된 정점끼리 색이 같다면 이분 그래프일 수 없음
                cout << "NO\n";
                return;
            }
        }
        if (q.empty()) { //어떤 정점과도 연결되지 않은 정점이 있을 수 있음
            for (int i = 1; i <= V; i++) {
                if (color[i] == 0) {
                    color[i] = 1;
                    q.push(i);
                    break;
                }
            }
        }
    }
    cout << "YES\n";
    return;
}

int main() {
    int K, first, second;

    cin >> K;
    for (int i = 0; i < K; i++) {
        cin >> V >> E;
        graph.assign((V + 1), vector<int>(0)); //(V+1)x(0)의 크기 할당
        color.assign((V + 1), 0);
        for (int j = 0; j < E; j++) { //graph[source].push_back(dest)
            cin >> first >> second;
            graph[first].push_back(second);
            graph[second].push_back(first);
        }
        bfs();
        graph.clear(); //2차원 벡터 초기화
        color.clear(); //1차원 벡터 초기화
    }
}