#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, ans = 0;

    cin >> n;
    vector<int> tree(n);
    for (int i = 0; i < n; i++)
        cin >> tree[i];
    sort(tree.begin(), tree.end(), greater<>()); //내림차순
    for (int i = 0; i < n; i++) //다 자라는데 걸리는 시간
        ans = max(ans, tree[i] + i + 1);
    cout << ans + 1; //다음날 초대
}