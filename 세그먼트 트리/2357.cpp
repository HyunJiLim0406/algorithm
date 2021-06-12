#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
typedef pair<int, int> pp;
const int INF = 1e9 + 1;

vector<pp> seg_tree;

pp initTree(vector<int> &arr, int left, int right, int node) {
    if (left == right) //leaf-node
        return seg_tree[node] = make_pair(arr[left], arr[left]);
    int mid = (left + right) / 2; //분할
    pp l = initTree(arr, left, mid, node * 2);
    pp r = initTree(arr, mid + 1, right, node * 2 + 1);
    return seg_tree[node] = make_pair(min(l.first, r.first), max(l.second, r.second));
}

pp findTree(int l_pos, int r_pos, int left, int right, int node) {
    if (l_pos > right || r_pos < left) //범위를 벗어남
        return make_pair(INF, 0);
    if (l_pos <= left && right <= r_pos) //트리의 범위가 0~2인데 0~3 사이의 값을 구하는 경우
        return seg_tree[node];
    int mid = (left + right) / 2; //분할
    pp l = findTree(l_pos, r_pos, left, mid, node * 2);
    pp r = findTree(l_pos, r_pos, mid + 1, right, node * 2 + 1);
    return make_pair(min(l.first, r.first), max(l.second, r.second));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, a, b;

    cin >> N >> M;
    int h = (int) ceil(log2(N)); //트리의 높이
    int tree_size = (1 << (h + 1)); //트리의 크기
    seg_tree.assign(tree_size, make_pair(0, 0));
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    initTree(arr, 0, N - 1, 1); //초기화
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        pp result = findTree(a - 1, b - 1, 0, N - 1, 1);
        cout << result.first << ' ' << result.second << '\n';
    }
}