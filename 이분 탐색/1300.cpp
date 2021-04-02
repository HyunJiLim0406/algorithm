#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
ll N, k;

ll cntLower(ll num) {
    ll cnt = 0;

    for (ll i = 1; i <= N; i++)
        cnt += min(num / i, N);
    return cnt;
}

ll lowerSearch(ll left, ll right) { //lower bound를 구해야 함
    while (left <= right) {
        ll mid = (left + right) / 2;
        if (k <= cntLower(mid))  //왼쪽 탐색
            right = mid - 1;
        else if (k > cntLower(mid)) //오른쪽 탐색
            left = mid + 1;
    }
    return right + 1;
}

int main() {
    cin >> N >> k;

    cout << lowerSearch(1, k);
}