#include <iostream>
#include <vector>

using namespace std;

vector<int> population;
vector<vector<int>> tree, dp;

int fillDp(int cur, int before, bool flag) {
    if (dp[cur][flag] != -1) //이미 계산된 상태면 바로 리턴
        return dp[cur][flag];

    dp[cur][flag] = 0; //초기화
    int size = tree[cur].size();
    if (flag) { //이번 마을이 우수마을
        for (int i = 0; i < size; i++) {
            if (tree[cur][i] == before) //부모 노드 제외
                continue;
            dp[cur][flag] += fillDp(tree[cur][i], cur, false); //자식 노드는 다 우수마을이 아님
        }
        dp[cur][flag] += population[cur]; //인구 수 더하기
    } else { //이번 마을이 우수마을이 아님
        for (int i = 0; i < size; i++) {
            if (tree[cur][i] == before) //부모 노드 제외
                continue;
            dp[cur][flag] += max(fillDp(tree[cur][i], cur, true), fillDp(tree[cur][i], cur, false)); //자식 노드는 우수마을이거나 아니거나
        }
    }
    return dp[cur][flag];
}

int main() {
    int n, u, v;

    cin >> n;
    population.assign(n + 1, 0);
    tree.assign(n + 1, vector<int>(0));
    dp.assign(n + 1, vector<int>(2, -1));
    for (int i = 1; i <= n; i++)
        cin >> population[i];
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    cout << max(fillDp(1, 0, true), fillDp(1, 0, false)); //root가 우수마을이거나 아니거나
}