#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> arr, seg_tree;

int initTree(int left, int right, int node) {
    if (left == right)
        return seg_tree[node] = arr[left];
    int mid = (left + right) / 2;
    return seg_tree[node] = max(initTree(left, mid, node * 2), initTree(mid + 1, right, node * 2 + 1));
}

int findTree(int left, int right, int l, int r, int node) {
    if (left > r || right < l)
        return 0;
    if (l <= left && right <= r)
        return seg_tree[node];
    int mid = (left + right) / 2;
    return max(findTree(left, mid, l, r, node * 2), findTree(mid + 1, right, l, r, node * 2 + 1));
}

//시간초과
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;
    arr.assign(n, 0);
    int h = (int) ceil(log2(n));
    int tree_size = (1 << (h + 1));
    seg_tree.assign(tree_size, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    initTree(0, n - 1, 1);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int max_height = findTree(0, n - 1, i + 1, j - 1, 1);
            if (max_height <= arr[i] && max_height <= arr[j])
                ans++;
        }
    }
    cout << ans;
}