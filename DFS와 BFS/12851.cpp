#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int INF = 1e9;
typedef pair<int, int> pp;

vector<pp> min_dist; //최단 거리, 진입 횟수
queue<int> q;

void possiblePos(int cur, int pos) {
    int cnt = min_dist[pos].second;
    if ((pos >= 0) && (pos < min_dist.size()) && (min_dist[pos].first > min_dist[cur].first)) { //방문했어도 최단 거리라면 큐에 넣기
        min_dist[pos] = make_pair(min_dist[cur].first + 1, cnt + 1);
        q.push(pos);
    }
}

pp bfs(int start, int target) {
    int t_dist = 1e9;
    min_dist[start] = make_pair(0, 1);
    q.push(start);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == target) //목표 지점의 최단 거리 저장
            t_dist = min_dist[cur].first;
        if (min_dist[cur].first >= t_dist) //이미 목표 지점의 최단 거리가 나왔다면 그 이상 탐색할 필요 없음
            continue;
        possiblePos(cur, cur - 1); //X-1
        possiblePos(cur, cur + 1); //X+1
        possiblePos(cur, cur * 2); //2*X
    }
    return min_dist[target];
}

int main() {
    int N, K;
    cin >> N >> K;
    min_dist.assign(100001, make_pair(INF, 0));
    pair<int, int> result = bfs(N, K);
    cout << result.first << '\n' << result.second;
}