#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> ci;

vector<bool> visited;

ci findGiga(int root, vector<vector<ci>> &tree) {
    int len = 0, pos = tree.size() - 1; //가지의 길이, 기가 위치(리프노드로 초기화)

    if (tree[root].empty() || tree[root].size() == 2) //루트가 기가일 때
        return {root, 0};
    do {
        if (tree[root].size() > 2) { //기가라면
            pos = root;
            break;
        }
        visited[root] = true; //방문 처리
        int next = (visited[tree[root][0].first]) ? 1 : 0; //다음 위치
        len += tree[root][next].second;
        root = tree[root][next].first;
    } while (tree[root].size() != 1); //리프노드 만날 때까지
    return {pos, len};
}

int branchLen(int cur, vector<vector<ci>> &tree) {
    visited[cur] = true; //방문처리
    int len = 0;
    for (int i = 0; i < tree[cur].size(); i++) {
        if (visited[tree[cur][i].first])
            continue;
        len = max(len, tree[cur][i].second + branchLen(tree[cur][i].first, tree)); //더 긴 가지
    }
    return len;
}

int main() {
    int n, r, a, b, d;

    cin >> n >> r;
    vector<vector<ci>> tree(n + 1, vector<ci>(0));
    visited.assign(n + 1, false);
    for (int i = 0; i < n - 1; i++) { //유방향인줄 알았는데 무방향이었다.
        cin >> a >> b >> d;
        tree[a].emplace_back(b, d);
        tree[b].emplace_back(a, d);
    }

    ci giga = findGiga(r, tree);
    cout << giga.second << ' ' << branchLen(giga.first, tree);
}