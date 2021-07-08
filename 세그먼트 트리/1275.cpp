#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

vector<ll> arr, seg_tree;

ll initTree(int left, int right, int node) {
    if (left == right) //leaf-node
        return seg_tree[node] = arr[left];
    int mid = (left + right) / 2; //분할
    return seg_tree[node] = initTree(left, mid, node * 2) + initTree(mid + 1, right, node * 2 + 1);
}

void updateTree(int left, int right, int pos, ll diff, int node) {
    if (pos < left || right < pos) //범위를 벗어남
        return;
    seg_tree[node] += diff; //갱신
    if (left == right) //leaf-node
        return;
    int mid = (left + right) / 2; //분할
    updateTree(left, mid, pos, diff, node * 2);
    updateTree(mid + 1, right, pos, diff, node * 2 + 1);
}

ll findTree(int l, int r, int left, int right, int node) {
    if (l > right || r < left) //범위를 벗어남
        return 0;
    if (l <= left && right <= r) //트리의 범위가 0~2인데 0~3 사이의 값을 구하는 경우
        return seg_tree[node];
    int mid = (left + right) / 2; //분할
    return findTree(l, r, left, mid, node * 2) + findTree(l, r, mid + 1, right, node * 2 + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q, x, y, a, b;

    cin >> N >> Q;
    arr.assign(N, 0);
    int h = (int) ceil(log2(N)); //트리의 높이
    int tree_size = (1 << (h + 1)); //트리의 크기
    seg_tree.assign(tree_size, 0);
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    initTree(0, N - 1, 1);
    while (Q--) {
        cin >> x >> y >> a >> b;
        if (x > y) //대소관계
            swap(x, y);
        cout << findTree(x - 1, y - 1, 0, N - 1, 1) << '\n';
        updateTree(0, N - 1, a - 1, b - arr[a - 1], 1);
        arr[a - 1] = b;
    }
}