#include <iostream>
#include <vector>

using namespace std;

vector<bool> isLie; //이 사람에게 거짓말을 할 수 있나?
vector<vector<int>> party_info; //파티 정보
vector<vector<int>> graph; //연결 정보

void dfs(int cur) { //거짓말을 할 수 없는 사람을 체크
    isLie[cur] = false;
    for (int i = 0; i < graph[cur].size(); i++) {
        if (isLie[graph[cur][i]])
            dfs(graph[cur][i]);
    }
}

int main() { //dfs 풀이
    int N, M, t, num, input;
    vector<int> init;

    cin >> N >> M;
    isLie.assign(N + 1, true);
    party_info.assign(M, vector<int>(0));
    graph.assign(N + 1, vector<int>(0));

    cin >> t;
    init.assign(t, 0);
    for (int i = 0; i < t; i++) //처음에 주어진 진실을 아는 사람
        cin >> init[i];
    for (int i = 0; i < M; i++) {
        cin >> num;
        for (int j = 0; j < num; j++) { //파티 정보
            cin >> input;
            party_info[i].push_back(input);
        }
        for (int j = 0; j < num - 1; j++) { //그래프에 연결관계 넣기
            for (int k = j + 1; k < num; k++) {
                graph[party_info[i][j]].push_back(party_info[i][k]);
                graph[party_info[i][k]].push_back(party_info[i][j]);
            }
        }
    }
    for (int i = 0; i < init.size(); i++) //dfs 돌면서 진실을 말해야 하는 사람 체크
        dfs(init[i]);

    int cnt = 0;
    for (int i = 0; i < M; i++) { //파티 정보의 첫번째 사람만 체크해도 됨
        if (isLie[party_info[i][0]])
            cnt++;
    }
    cout << cnt;
}