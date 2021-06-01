#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
typedef long long ll;

ll initTree(vector<ll> &seg_tree, vector<ll> &arr, int left, int right, int node) {
    if (left == right) //left-node
        return seg_tree[node] = arr[left];
    int mid = (left + right) / 2; //분할
    return seg_tree[node] =
                   initTree(seg_tree, arr, left, mid, node * 2) + initTree(seg_tree, arr, mid + 1, right, node * 2 + 1);
}

void updateTree(vector<ll> &seg_tree, int pos, ll diff, int left, int right, int node) {
    if (pos < left || pos > right) //범위를 벗어남
        return;
    seg_tree[node] += diff; //업데이트
    if (left == right) //left-node
        return;
    int mid = (left + right) / 2; //분할
    updateTree(seg_tree, pos, diff, left, mid, node * 2);
    updateTree(seg_tree, pos, diff, mid + 1, right, node * 2 + 1);
}

ll sumTree(vector<ll> &seg_tree, int l_pos, int r_pos, int left, int right, int node) {
    if (l_pos > right || r_pos < left) //범위를 벗어남
        return 0;
    if (l_pos <= left && right <= r_pos) //트리의 범위가 0~2인데 0~3 사이의 합을 구하는 경우
        return seg_tree[node];
    int mid = (left + right) / 2; //분할
    return sumTree(seg_tree, l_pos, r_pos, left, mid, node * 2) +
           sumTree(seg_tree, l_pos, r_pos, mid + 1, right, node * 2 + 1);
}

int main() { //범위때문에 고생함
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K, a, b;
    ll c;

    cin >> N >> M >> K;
    int h = (int) ceil(log2(N)); //트리의 높이
    int tree_size = (1 << (h + 1)); //트리의 크기
    vector<ll> seg_tree(tree_size);
    vector<ll> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    initTree(seg_tree, arr, 0, N - 1, 1); //초기화
    for (int i = 0; i < M + K; i++) {
        cin >> a >> b >> c;
        if (a == 1) { //업데이트
            updateTree(seg_tree, b - 1, c - arr[b - 1], 0, N - 1, 1);
            arr[b - 1] = c; //원래 배열도 수정해야 함
        } else if (a == 2) //합 구하기
            cout << sumTree(seg_tree, b - 1, (int) c - 1, 0, N - 1, 1) << '\n';
    }
}