#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

set<string> s;
vector<string> arr;
vector<bool> visited;

void backtracking(string cur, int n, int k, int cnt) { //가능한 모든 조합
    if (cnt == k) { //셋에 넣어서 중복 제거
        s.insert(cur);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (visited[i])
            continue;
        visited[i] = true; //visited 처리
        backtracking(cur + arr[i], n, k, cnt + 1);
        visited[i] = false; //unvisited 처리
    }
}

int main() {
    int n, k;

    cin >> n >> k;
    arr.assign(n, "");
    visited.assign(n, false);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    backtracking("", n, k, 0);
    cout << s.size();
}