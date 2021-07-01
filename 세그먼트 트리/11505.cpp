#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;
const int MODULAR = 1000000007;

vector<ll> arr, seg_tree;

ll initTree(int left, int right, int node) {
    if (left == right) //leaf-node
        return seg_tree[node] = arr[left];
    int mid = (left + right) / 2; //분할
    return seg_tree[node] = (initTree(left, mid, node * 2) *
                             initTree(mid + 1, right, node * 2 + 1)) % MODULAR;
}

ll updateTree(int update, int pos, int left, int right, int node) {
    if (left > pos || right < pos) //범위를 벗어남
        return seg_tree[node];
    if (left == right) //leaf-node
        return seg_tree[node] = update;
    int mid = (left + right) / 2; //분할
    return seg_tree[node] = (updateTree(update, pos, left, mid, node * 2) *
                             updateTree(update, pos, mid + 1, right, node * 2 + 1)) % MODULAR;
}

ll findTree(int l, int r, int left, int right, int node) {
    if (l > right || r < left) //범위를 벗어남
        return 1;
    if (l <= left && right <= r) //트리의 범위가 0~2인데 0~3 사이의 값을 구하는 경우
        return seg_tree[node];
    int mid = (left + right) / 2; //분할
    return (findTree(l, r, left, mid, node * 2) *
            findTree(l, r, mid + 1, right, node * 2 + 1)) % MODULAR;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, K, a, b, c;

    cin >> N >> M >> K;
    arr.assign(N, 0);
    int h = (int) ceil(log2(N)); //트리의 높이
    int tree_size = (1 << (h + 1)); //트리의 크기
    seg_tree.assign(tree_size, 0);
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    initTree(0, N - 1, 1); //트리 초기화
    for (int i = 0; i < M + K; i++) {
        cin >> a >> b >> c;
        if (a == 1) {
            updateTree(c, b - 1, 0, N - 1, 1); //트리 업데이트
            arr[b - 1] = c; //배열 업데이트
        } else if (a == 2)
            cout << findTree(b - 1, c - 1, 0, N - 1, 1) << '\n'; //구간 곱 출력
    }
}