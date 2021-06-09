#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;
vector<bool> visited;

void recurCycle(int cur) { //dfs지만 간단하게 처리 가능
    visited[cur] = true;
    if (!visited[arr[cur]])
        recurCycle(arr[cur]);
}

int main() {
    int T, N;

    cin >> T;
    while (T--) {
        cin >> N;
        arr.assign(N + 1, 0);
        visited.assign(N + 1, false);
        for (int i = 1; i <= N; i++)
            cin >> arr[i];

        int cnt = 0;
        for (int i = 1; i <= N; i++) {
            if (!visited[i]) { //미방문 정점
                cnt++;
                recurCycle(i);
            }
        }
        cout << cnt << '\n';
    }
}