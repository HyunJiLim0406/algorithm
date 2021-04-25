#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> v;
int parents[1000001];

void dfs(int cur) {
    for (int i = 0; i < v[cur].size(); i++) {
        if (parents[v[cur][i]] == 0) { //부모가 없으면 cur을 부모로
            parents[v[cur][i]] = cur;
            dfs(v[cur][i]);
        }
    }
}

int main() {
    int N, first, second;

    cin >> N;
    v.assign(N + 1, vector<int>(0));
    for (int i = 1; i < N; i++) {
        cin >> first >> second;
        v[first].push_back(second);
        v[second].push_back(first);
    }
    parents[1] = -1; //root의 부모는 -1
    dfs(1); //1부터 시작
    for (int i = 2; i <= N; i++)
        cout << parents[i] << '\n';
}
