#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> water(3);
vector<vector<vector<bool>>> visited;
set<int> s;

void dfs(vector<int> cur) {
    if (visited[cur[0]][cur[1]][cur[2]]) //이미 방문함
        return;
    visited[cur[0]][cur[1]][cur[2]] = true; //방문 처리
    if (cur[0] == 0) //A 물통이 비어 있을 때
        s.insert(cur[2]);

    for (int i = 0; i < 3; i++) {
        if (cur[i] != 0) { //i번 물통에 물이 있을 때
            for (int j = 0; j < 3; j++) {
                if (i == j || cur[j] == water[j]) //j와 i가 같은 물통이거나 j번 물통에 물이 가득 차있으면 안됨
                    continue;
                vector<int> tmp = cur;
                int puring = min(cur[i], water[j] - cur[j]); //i번 물통의 불을 다 붓거나 j번 물통이 가득찰 때까지만
                tmp[i] -= puring;
                tmp[j] += puring;
                dfs(tmp); //dfs 호출
            }
        }
    }
}

int main() {
    cin >> water[0] >> water[1] >> water[2];
    int size = max(water[0], max(water[1], water[2])); //최대 용량
    visited.assign(size + 1, vector<vector<bool>>(size + 1, vector<bool>(size + 1, false)));

    dfs({0, 0, water[2]});
    for (auto result : s)
        cout << result << ' ';
}