#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>

using namespace std;

string bfs(int source, int target) {
    vector<bool> visited;
    visited.assign(10000, false);
    queue<pair<int, string>> q;

    visited[source] = true;
    q.push(make_pair(source, ""));
    while (!q.empty()) { //벡터로 처리하려고 했는데 벡터 하나 썼다고 TLE 발생
        int cur = q.front().first;
        string str = q.front().second;
        q.pop();

        if (cur == target) //target 찾음
            return str;
        int next_num;

        next_num = (2 * cur) % 10000; //D
        if (!visited[next_num]) {
            visited[next_num] = true;
            q.push(make_pair(next_num, str + "D"));
        }

        next_num = (cur - 1 < 0) ? 9999 : cur - 1; //S
        if (!visited[next_num]) {
            visited[next_num] = true;
            q.push(make_pair(next_num, str + "S"));
        }

        next_num = ((cur % 1000) * 10) + (cur / 1000); //L
        if (!visited[next_num]) {
            visited[next_num] = true;
            q.push(make_pair(next_num, str + "L"));
        }

        next_num = ((cur % 10) * 1000) + (cur / 10); //R
        if (!visited[next_num]) {
            visited[next_num] = true;
            q.push(make_pair(next_num, str + "R"));
        }
    }
    return "";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, A, B;

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> A >> B;
        cout << bfs(A, B) << '\n';
    }
}