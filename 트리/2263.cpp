#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

vector<int> in, post;
map<int, pair<int, int>> tree;

int makeTree(int left, int right, int root_pos) { //left, right -> inorder 범위, root_pos -> postorder 끝 값
    if (left > right) //분할 종료 조건
        return -1;
    int root = find(in.begin(), in.end(), post[root_pos]) - in.begin(); //루트노드의 idx
    int left_node = makeTree(left, root - 1, (root_pos - 1) - (right - root)); //right-root = root의 오른쪽 자식들의 수
    int right_node = makeTree(root + 1, right, root_pos - 1); //root의 오른쪽 자식 값은 root_pos 바로 왼쪽에 위치
    tree[in[root]] = make_pair(left_node, right_node); //트리 생성
    return in[root]; //root 반환
}

void preorder(int node) { //preorder 출력
    cout << node << ' ';
    if (tree[node].first != -1)
        preorder(tree[node].first);
    if (tree[node].second != -1)
        preorder(tree[node].second);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, input;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> input;
        in.push_back(input);
    }
    for (int i = 0; i < n; i++) {
        cin >> input;
        post.push_back(input);
    }
    int root_node = makeTree(0, in.size() - 1, in.size() - 1);
    preorder(root_node);
}