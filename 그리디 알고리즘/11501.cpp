#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n;

    cin >> t;
    while (t--) {
        long long ans = 0;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int max_stock = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) { //뒤에서부터
            if (arr[i] > max_stock) //제일 비싼 날
                max_stock = arr[i];
            else //팔기
                ans += max_stock - arr[i];
        }
        cout << ans << '\n';
    }
}