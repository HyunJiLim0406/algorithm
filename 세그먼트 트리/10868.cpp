#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> arr, seg_tree;

int initTree(int left, int right, int node) {
    if (left == right) //leaf-node
        return seg_tree[node] = arr[left];
    int mid = (left + right) / 2; //분할
    return seg_tree[node] = min(initTree(left, mid, node * 2),
                                initTree(mid + 1, right, node * 2 + 1));
}

int findTree(int l_pos, int r_pos, int left, int right, int node) {
    if (l_pos > right || r_pos < left) //범위를 벗어남
        return 1e9 + 1;
    if (l_pos <= left && right <= r_pos) //트리의 범위가 0~2인데 0~3 사이의 값을 구하는 경우
        return seg_tree[node];
    int mid = (left + right) / 2; //분할
    return min(findTree(l_pos, r_pos, left, mid, node * 2),
               findTree(l_pos, r_pos, mid + 1, right, node * 2 + 1));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, a, b;

    cin >> N >> M;
    int h = (int) ceil(log2(N)); //트리의 높이
    int tree_size = (1 << (h + 1)); //트리의 크기
    seg_tree.assign(tree_size, 0);
    arr.assign(N, 0);

    for (int i = 0; i < N; i++)
        cin >> arr[i];
    initTree(0, N - 1, 1);
    while (M--) {
        cin >> a >> b;
        cout << findTree(a - 1, b - 1, 0, N - 1, 1) << '\n';
    }
}