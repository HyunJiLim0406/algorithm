#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <utility>

using namespace std;

map<int, pair<int, int>> tree; //트리
vector<vector<int>> levels; //레벨별로 각 정점 저장
vector<int> row; //각 정점의 열

int levelTraversal(int root) { //레벨 순회
    int cur, level;
    queue<pair<int, int>> node;
    node.push(make_pair(root, 1));
    while (!node.empty()) {
        cur = node.front().first;
        level = node.front().second;
        node.pop();
        levels[level].push_back(cur);
        if (tree[cur].first != -1)
            node.push(make_pair(tree[cur].first, level + 1));
        if (tree[cur].second != -1)
            node.push(make_pair(tree[cur].second, level + 1));
    }
    return level; //높이 반환
}

int cnt = 1;
void inorder(int node) { //중위 순위하며 각 정점의 열 저장
    if (tree[node].first != -1)
        inorder(tree[node].first);
    row[node] = cnt++;
    if (tree[node].second != -1)
        inorder(tree[node].second);
}

int main() {
    int N, node, l, r, root;
    vector<bool> parent; //root 확인용
    pair<int, int> result = {1, 1}; //최대 너비, 레벨

    cin >> N;
    levels.assign(N + 1, vector<int>(0));
    row.assign(N + 1, 0);
    parent.assign(N + 2, false);
    for (int i = 0; i < N; i++) {
        cin >> node >> l >> r;
        tree[node] = make_pair(l, r);
        parent[l + 1] = parent[r + 1] = true;
    }
    for (int i = 1; i <= N + 1; i++) { //부모 정점이 없다면 root
        if (!parent[i])
            root = i - 1;
    }

    int height = levelTraversal(root); //레벨 순회
    inorder(root); //중위 순회
    for (int i = 1; i <= height; i++) { //각 레벨마다
        int width = row[levels[i][levels[i].size() - 1]] - row[levels[i][0]] + 1; //(마지막 값-첫번째 값) = 해당 레벨의 너비
        if (width > result.second) { //갱신
            result.first = i;
            result.second = width;
        }
    }
    cout << result.first << ' ' << result.second;
}