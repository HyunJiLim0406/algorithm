#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<string> refactor(string str) { //한 줄 입력 벡터로 리팩토링
    str += " ";
    string tmp;
    vector<string> result;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == ' ') {
            result.push_back(tmp);
            tmp = "";
            continue;
        }
        tmp += str[i];
    }
    return result;
}

int topology(vector<int> &indegree, vector<int> &info, vector<vector<int>> &graph) {
    vector<int> dp(26, 0);
    queue<int> q;
    int ans = 0;

    for (int i = 0; i < 26; i++) {
        if (info[i] && !indegree[i]) { //존재하는 노드이며 시작 노드
            dp[i] = info[i];
            q.push(i);
        }
    }

    while (!q.empty()) {
        int node = q.front();
        int t = dp[node];
        q.pop();

        ans = max(ans, t);
        for (int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i];
            dp[next_node] = max(dp[next_node], t); //가장 오래걸리는 시간 갱신
            indegree[next_node]--;
            if (!indegree[next_node]) { //큐에 삽입
                dp[next_node] += info[next_node];
                q.push(next_node);
            }
        }
    }
    return ans;
}

int main() {
    string input;

    vector<int> indegree(26, 0), info(26, 0);
    vector<vector<int>> graph(26, vector<int>(0));
    while (getline(cin, input)) {
        vector<string> list = refactor(input);
        int idx = list[0][0] - 'A';
        info[idx] = stoi(list[1]);
        if (list.size() == 2)
            continue;
        for (int i = 0; i < list[2].size(); i++) {
            indegree[idx]++;
            graph[list[2][i] - 'A'].push_back(idx);
        }
    }
    cout << topology(indegree, info, graph);
}