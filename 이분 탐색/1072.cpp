#include <iostream>

using namespace std;
typedef long long ll;

ll X, Y;

ll lowerSearch(ll left, ll right, ll winning_rate) { //lower-bound
    while (left <= right) {
        ll mid = (left + right) / 2;
        ll win = (((Y + mid) * 100) / (X + mid)); //새로운 승률
        if (win >= winning_rate) //왼쪽 탐색
            right = mid - 1;
        else //오른쪽 탐색
            left = mid + 1;
    }
    return right + 1;
}

int main() {
    cin >> X >> Y;
    ll winning_rate = ((Y * 100) / X);
    if (winning_rate >= 99) //승률이 99% 이상이라면
        cout << -1;
    else
        cout << lowerSearch(0, X, winning_rate + 1);
}