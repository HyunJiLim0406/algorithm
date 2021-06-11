#include <iostream>
#include <vector>

using namespace std;

int cnt;
vector<vector<int>> tree;

void leafNum(int node, int del) {
    bool isLeaf = true;
    for (int i = 0; i < tree[node].size(); i++) {
        if (tree[node][i] != del) { //탐색 가능한 자식이 있는지
            isLeaf = false;
            leafNum(tree[node][i], del);
        }
    }
    if (isLeaf) //리프 노드
        cnt++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, input, root;

    cin >> N;
    tree.assign(N, vector<int>(0));
    for (int i = 0; i < N; i++) {
        cin >> input;
        if (input != -1) //자식 정보 입력
            tree[input].push_back(i);
        else //root 노드 입력
            root = i;
    }
    cin >> input;
    if (root == input) //루트 노드를 지우는 경우
        cout << 0;
    else {
        leafNum(root, input);
        cout << cnt;
    }
}