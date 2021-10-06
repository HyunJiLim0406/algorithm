#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    long long ans = 0;

    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());
    for (int i = 1; i <= n; i++)
        ans += abs(arr[i-1] - i);

    cout << ans;
}