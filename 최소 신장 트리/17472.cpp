#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;
typedef pair<int, int> pp;

int N, M;
vector<vector<int>> board;
vector<int> parent;
priority_queue<pair<int, pp>, vector<pair<int, pp>>, greater<pair<int, pp>>> pq; //min-heap
pp dir[4] = {{-1, 0},
             {1,  0},
             {0,  -1},
             {0,  1}};

void dfs(pp cur, int mark) { //같은 구역의 섬을 같은 mark로 표시
    board[cur.first][cur.second] = mark;
    for (int i = 0; i < 4; i++) {
        int nr = cur.first + dir[i].first;
        int nc = cur.second + dir[i].second;
        if ((nr >= 0) && (nr < N) && (nc >= 0) && (nc < M) && (board[nr][nc] == 1))
            dfs(make_pair(nr, nc), mark);
    }
}

void findBridge(pp cur) {
    int row = cur.first;
    int col = cur.second;
    int mark = board[row][col];
    for (int i = 0; i < 4; i++) { //상하좌우로 계속 다리 만들어보기
        int tmp_r = row + dir[i].first;
        int tmp_c = col + dir[i].second;
        int dist = 0; //다리의 길이
        while ((tmp_r >= 0) && (tmp_r < N) && (tmp_c >= 0) && (tmp_c < M) && (board[tmp_r][tmp_c] == 0)) { //범위 내에 있고, 바다인 동안 직진
            tmp_r += dir[i].first;
            tmp_c += dir[i].second;
            dist++;
        }
        if ((tmp_r >= 0) && (tmp_r < N) && (tmp_c >= 0) && (tmp_c < M)) { //범위 내에 있고
            if ((board[tmp_r][tmp_c] != mark) && (dist > 1)) { //새로운 섬인데 거리가 1보다 크다면 우선순위 큐에 넣기
                pq.push(make_pair(dist, make_pair(mark, board[tmp_r][tmp_c])));
            }
        }
    }
}

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

    while (!pq.empty()) {
        if (cnt == (V - 1)) //다리의 수가 (섬의 수)-1 이라면 리턴
            return weight;
        int dist = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;

        pq.pop();
        if (unionInput(x, y)) { //x, y를 유니온할 수 있다면
            cnt++;
            weight += dist;
        }
    }
    return -1; //mst를 만들지 못함
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    board.assign(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            cin >> board[i][j];
    }
    int idx = 2; //섬의 수 저장
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 1) //dfs로 각 섬마다 번호 매기기
                dfs(make_pair(i, j), idx++);
        }
    }
    parent.assign(idx, -1); //parent 벡터 할당
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] > 0) //해당 땅에서 만들 수 있는 다리 찾기
                findBridge(make_pair(i, j));
        }
    }
    cout << kruskalMst(idx - 2); //섬의 수는 (idx-2)개
}