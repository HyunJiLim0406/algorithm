#include <iostream>
#include <vector>

using namespace std;

int main() {
    int k;

    cin >> k;
    vector<int> arr(1 << k);
    vector<vector<int>> ans(k, vector<int>(0));
    for (int i = 1; i < (1 << k); i++)
        cin >> arr[i];

    for (int i = 0; i < k; i++) {
        int idx = 1 << i, jump = 1 << (i + 1); //레벨 시작, 건너뛸 인덱스
        for (int j = idx; j < arr.size(); j += jump)
            ans[k - i - 1].push_back(arr[j]);
    }

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << ' ';
        cout << '\n';
    }
}