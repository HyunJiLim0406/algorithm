#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>
#include <queue>

using namespace std;

unordered_set<string> nodes;
unordered_map<string, int> indegree;

vector<string> topology(int n, unordered_map<string, vector<string>> &graph) {
    vector<string> result;
    queue<string> q;
    for (auto node: nodes) { //초기화
        if (!indegree[node])
            q.push(node);
    }

    while (!q.empty()) {
        int size = q.size();
        set<string> tmp;
        while (size--) { //이번에 담을 아이템
            string node = q.front();
            q.pop();
            tmp.insert(node);

            for (int i = 0; i < graph[node].size(); i++) {
                string next_node = graph[node][i];
                indegree[next_node]--;
                if (!indegree[next_node]) //다음에 담을 수 있음
                    q.push(next_node);
            }
        }
        for (auto s: tmp) //셋의 내용 벡터에 옮기기
            result.push_back(s);
    }
    if (result.size() != n) //아이템을 다 담지 못함
        return {"-1"};
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string a, b;
    unordered_map<string, vector<string>> graph;

    cin >> n;
    while (n--) {
        cin >> a >> b;
        nodes.insert(a);
        nodes.insert(b);
        indegree[b]++;
        graph[a].push_back(b);
    }

    vector<string> ans = topology(nodes.size(), graph);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << '\n';
}