#include <iostream>
#include <vector>

using namespace std;

int steal(int n, int m, int k, vector<int> &house) {
    int money = 0, ans = 0;
    for (int i = 0; i < m; i++)
        money += house[i];
    if (n == m) //훔칠 수 있는 경우 1개
        return money < k;
    int left = 0, right = m - 1;
    do {
        if (money < k) //훔칠 수 있음
            ans++;
        //윈도우 이동
        right = (right + 1) % n;
        money += house[right];
        money -= house[left];
        left = (left + 1) % n;
    } while (left != 0);
    return ans;
}

int main() {
    int t, n, m, k;

    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        vector<int> house(n, 0);
        for (int i = 0; i < n; i++)
            cin >> house[i];
        cout << steal(n, m, k, house) << '\n';
    }
}