#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;
vector<int> indegree;

vector<int> topology(int n) {
    vector<int> result;
    queue<int> q;
    for (int i = 1; i <= n; i++) { //시작 정점 큐에 넣기
        if (!indegree[i])
            q.push(i);
    }
    while (q.size() == 1) { //순위가 모호하지 않으려면 큐의 크기는 항상 1
        int node = q.front();
        q.pop();

        result.push_back(node);
        for (int i = 0; i < graph[node].size(); i++) {
            int next = graph[node][i];
            indegree[next]--;
            if (!indegree[next]) //다음에 접근 가능한 정점
                q.push(next);
        }
    }
    if (result.size() == n) //모든 순위를 찾아냄
        return result;
    if (q.empty()) //순위를 정하지 못함
        cout << "IMPOSSIBLE\n";
    else if (q.size() > 1) //순위가 모호함
        cout << "?\n";
    return {};
}

int main() {
    int t, n, m, a, b;

    cin >> t;
    while (t--) {
        cin >> n;
        indegree.assign(n + 1, 0);
        graph.assign(n + 1, vector<int>(0));
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        for (int i = 0; i < n - 1; i++) { //초기 입력
            for (int j = i + 1; j < n; j++) {
                indegree[arr[j]]++;
                graph[arr[i]].push_back(arr[j]);
            }
        }
        cin >> m;
        while (m--) {
            cin >> a >> b;
            if (find(arr.begin(), arr.end(), a) > find(arr.begin(), arr.end(), b)) //b->a 관계인지 확인
                swap(a, b);
            //간선 정보 뒤집기
            graph[a].erase(find(graph[a].begin(), graph[a].end(), b));
            graph[b].push_back(a);
            //indegree 수정
            indegree[a]++;
            indegree[b]--;
        }
        vector<int> result = topology(n);
        if (!result.empty()) {
            for (int i = 0; i < n; i++)
                cout << result[i] << ' ';
            cout << '\n';
        }
    }
}