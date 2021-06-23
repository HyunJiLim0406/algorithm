#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<int> jump;

int bfs() {
    queue<int> q;
    vector<int> dist(N, -1);
    dist[0] = 0;
    q.push(0);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == N - 1) //도착 지점 도달
            return dist[cur];
        for (int i = 0; i <= jump[cur]; i++) {
            if (cur + i < N && dist[cur + i] == -1) { //범위 내에 있는 미방문 지점
                dist[cur + i] = dist[cur] + 1;
                q.push(cur + i);
            }
        }
    }
    return -1;
}

int main() {
    cin >> N;
    jump.assign(N, 0);
    for (int i = 0; i < N; i++)
        cin >> jump[i];
    cout << bfs();
}