#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cnt = 0;
int choose[100001];
bool visited[100001], check[100001];

void dfs(int cur) {
    visited[cur] = true;
    int next_node = choose[cur];
    if (!visited[next_node]) //미방문 정점
        dfs(next_node);
    else if (!check[next_node]) { //방문했는데 !check면 사이클
        int tmp = choose[next_node];
        while (tmp != next_node) { //사이클 포함 노드 수 계산
            tmp = choose[tmp];
            cnt++;
        }
        cnt++;
    }
    check[cur] = true; //check
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T, n;
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> n;
        cnt = 0;
        fill(choose, choose + n + 1, 0);
        fill(visited, visited + n + 1, false);
        fill(check, check + n + 1, false);
        for (int i = 1; i <= n; i++)
            cin >> choose[i];
        for (int i = 1; i <= n; i++) {
            if (!visited[i])
                dfs(i);
        }
        cout << n - cnt << '\n';
    }
}