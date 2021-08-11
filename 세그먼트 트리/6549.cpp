#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;
const int MAX = 1e9 + 1;

vector<int> arr, seg_tree;

int initTree(int left, int right, int node) {
    if (left == right) //leaf-node
        return seg_tree[node] = left; //최소 높이의 인덱스 저장
    int mid = (left + right) / 2; //분할
    int left_idx = initTree(left, mid, node * 2);
    int right_idx = initTree(mid + 1, right, node * 2 + 1);
    if (arr[left_idx] > arr[right_idx])
        return seg_tree[node] = right_idx;
    return seg_tree[node] = left_idx;
}

int findTree(int l, int r, int left, int right, int node) {
    if (l > right || r < left) //범위를 벗어남
        return arr.size() - 1;
    if (l <= left && right <= r) //트리의 범위가 0~2인데 0~3 사이의 값을 구하는 경우
        return seg_tree[node];
    int mid = (left + right) / 2; //분할
    int left_idx = findTree(l, r, left, mid, node * 2);
    int right_idx = findTree(l, r, mid + 1, right, node * 2 + 1);
    if (arr[left_idx] > arr[right_idx])
        return right_idx;
    return left_idx;
}

ll maxArea(int left, int right, int n) {
    if (left > right) //재귀 종료 조건
        return 0;
    int mid_idx = findTree(left, right, 0, n - 1, 1); //높이가 가장 낮은 직사각형의 인덱스
    ll area = (ll) (right - left + 1) * (ll) arr[mid_idx]; //넓이
    return max(area, max(maxArea(left, mid_idx - 1, n), maxArea(mid_idx + 1, right, n))); //분할해서 비교 후 최댓값 리턴
}

int main() {
    int n;

    while (true) {
        cin >> n;
        if (!n)
            break;

        int h = ceil(log2(n)); //트리의 높이
        int tree_size = 1 << (h + 1); //트리의 크기
        seg_tree.assign(tree_size, 0);
        arr.assign(n + 1, 0);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        arr[n] = MAX; //범위를 벗어난 경우를 위해 넣는 추가 데이터
        initTree(0, n - 1, 1);
        cout << maxArea(0, n - 1, n) << '\n';
    }
}