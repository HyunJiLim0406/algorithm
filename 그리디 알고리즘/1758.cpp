#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;

    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end(), greater<>()); //내림차순 정렬

    long long ans = 0;
    for (int i = 0; i < n; i++) { //팁을 많이 주려던 사람부터 주기
        ans += max(0, arr[i] - (i + 1 - 1));
    }
    cout << ans;
}