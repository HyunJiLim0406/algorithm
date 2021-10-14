#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

vector<vector<int>> graph;

vector<int> rumor(int n, vector<int> &init) {
    vector<int> check(n + 1, -1); //루머를 언제부터 믿었는지
    vector<int> believer(n + 1, 0); //주변에서 루머를 믿는 사람
    queue<int> q;

    for (int i = 0; i < init.size(); i++) { //초기화
        check[init[i]] = 0;
        q.push(init[i]);
    }

    while (!q.empty()) {
        int cur = q.front();
        int t = check[cur];
        q.pop();

        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i];
            believer[next]++; //주변에서 루머를 믿는 사람 증가
            if (check[next] != -1)
                continue;
            if (believer[next] >= (ceil)(graph[next].size() / 2.0)) { //절반 이상이 믿으면
                check[next] = t + 1;
                q.push(next);
            }
        }
    }
    return check;
}

int main() {
    int n, m;

    cin >> n;
    graph.assign(n + 1, vector<int>(0));
    for (int i = 1; i <= n; i++) {
        int input = 0;
        while (true) {
            cin >> input;
            if (!input)
                break;
            graph[i].push_back(input);
        }
    }

    cin >> m;
    vector<int> init(m, 0);
    for (int i = 0; i < m; i++)
        cin >> init[i];

    vector<int> ans = rumor(n, init);
    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
}