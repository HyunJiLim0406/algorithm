#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, color = 0;

    cin >> n;
    vector<pair<int, int>> input(n);
    for (int i = 0; i < n; i++) {
        cin >> input[i].first >> input[i].second;
        color = max(color, input[i].second);
    }

    sort(input.begin(), input.end());
    vector<vector<int>> graph(color + 1, vector<int>(0));

    for (int i = 0; i < n; i++) //색 별로 입력
        graph[input[i].second].push_back(input[i].first);

    int ans = 0;
    for (int i = 0; i <= color; i++) {
        for (int j = 0; j < graph[i].size(); j++) { //양 옆 중 가장 가까운 것
            int tmp = 1e6;
            if (j != 0)
                tmp = min(tmp, graph[i][j] - graph[i][j - 1]);
            if (j != graph[i].size() - 1)
                tmp = min(tmp, graph[i][j + 1] - graph[i][j]);
            ans += tmp;
        }
    }

    cout << ans;
}