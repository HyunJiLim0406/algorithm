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

    int ans = 0, idx = 0;
    while (idx < n / 3 * 3) { //3개씩 묶어서 더하기
        ans += (arr[idx] + arr[idx + 1]);
        idx += 3;
    }
    for (int i = idx; i < n; i++) //묶을 수 없는 상품
        ans += arr[i];
    cout << ans;
}