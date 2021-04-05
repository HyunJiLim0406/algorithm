#include <iostream>
#include <cstring>
#include <stack>
#include <queue>

using namespace std;

int matrix[1001][1001]; //정점 i와 j 사이에 간선이 존재하면 matrix[i][j]=1
bool visited[1001] = {false}; //정점의 방문 여부

void dfs(int start, int max) { //스택으로 구현, 재귀로 구현해도 됨
    stack<int> s;

    s.push(start);
    while (!s.empty()) {
        int cur = s.top();
        s.pop();
        if (!visited[cur]) { //스택에 들어갈 땐 !visited 였으나 나온 순간에는 아닐 수도 있음
            visited[cur] = true;
            cout << cur << ' ';
            for (int i = max; i >= 1; i--) { //연결된 정점 중 아직 방문하지 않은 정점을 스택에 넣음
                if (matrix[cur][i] == 1 && !visited[i])
                    s.push(i);
            }
        }
    }
}

void bfs(int start, int max) { //큐로 구현
    queue<int> q;

    q.push(start);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (!visited[cur]) { //큐에 들어갈 땐 !visited 였으나 나온 순간에는 아닐 수도 있음
            visited[cur] = true;
            cout << cur << ' ';
            for (int i = 1; i <= max; i++) { //연결된 정점 중 아직 방문하지 않은 정점을 큐에 넣음
                if (matrix[cur][i] == 1 && !visited[i])
                    q.push(i);
            }
        }
    }
}

int main() {
    int N, M, V, first, second;

    cin >> N >> M >> V;
    for (int i = 0; i < M; i++) {
        cin >> first >> second;
        matrix[first][second] = 1;
        matrix[second][first] = 1;
    }
    dfs(V, N);
    memset(visited, false, sizeof(visited));
    cout << '\n';
    bfs(V, N);
}