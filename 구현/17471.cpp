#include <iostream>
#include <vector>

using namespace std;

vector<bool> split, visited;
vector<int> population;
vector<vector<int>> graph;

int calcDiff() { //두 선거구의 인구 차이
    int blue = 0, red = 0;
    for (int i = 1; i < split.size(); i++) {
        if (split[i])
            blue += population[i];
        else
            red += population[i];
    }
    return abs(blue - red);
}

void dfs(int cur) {
    visited[cur] = true; //방문 처리
    for (int i = 0; i < graph[cur].size(); i++) {
        int node = graph[cur][i];
        if (split[node] == split[cur] && !visited[node]) //같은 선거구이면서 방문하지 않은 곳일 때
            dfs(node);
    }
}

int main() {
    int N, num, input, result = 10000;

    cin >> N;
    graph.assign(N + 1, vector<int>(0));
    population.assign(N + 1, 0);
    split.assign(N + 1, false);
    for (int i = 1; i <= N; i++)
        cin >> population[i];
    for (int i = 1; i <= N; i++) {
        cin >> num;
        while (num--) {
            cin >> input;
            graph[i].push_back(input);
        }
    }
    for (int i = 1; i < (1 << N) - 1; i++) { //비트마스크 조합
        for (int j = 0; j < N; j++) //각 선거구로 나눠줌
            split[j + 1] = (i & (1 << j)) != 0;
        int diff = calcDiff(); //인구 수 차이
        if (diff >= result) //최솟값보다 크다면 탐색할 필요 없음
            continue;

        visited.assign(N + 1, false);
        int cnt = 0; //dfs를 돈 횟수
        for (int j = 1; j <= N && cnt < 3; j++) { //각 선거구가 연결됐다면 dfs가 2번만 실행돼야 함
            if (!visited[j]) {
                cnt++;
                dfs(j);
            }
        }
        if (cnt == 2) //각 선거구가 연결됐다면 갱신
            result = diff;
    }
    cout << ((result == 10000) ? -1 : result); //출력
}