#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> preorder;
map<int, int> inorder_idx;

void divide(int idx, int left, int right) {
    if (left > right) //기저 조건
        return;
    int root = preorder[idx]; //루트의 값
    int root_idx = inorder_idx[root]; //중위 순회에서 루트의 위치

    divide(idx + 1, left, root_idx - 1); //왼쪽 서브트리
    divide(idx + (root_idx - left) + 1, root_idx + 1, right); //오른쪽 서브트리
    cout << root << ' ';
}

int main() {
    int t, n, num;

    cin >> t;
    while (t--) {
        cin >> n;
        preorder.assign(n, 0);

        for (int i = 0; i < n; i++)
            cin >> preorder[i];
        for (int i = 0; i < n; i++) {
            cin >> num;
            inorder_idx[num] = i;
        }
        divide(0, 0, n - 1);
        cout << '\n';
        inorder_idx.clear();
    }
}