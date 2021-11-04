#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t, n, m;

    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<int> a(n), b(m);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];
        sort(b.begin(), b.end()); //정렬

        int ans = 0;
        for (int i = 0; i < n; i++) //이분 탐색
            ans += (lower_bound(b.begin(), b.end(), a[i]) - b.begin());
        cout << ans << '\n';
    }
}