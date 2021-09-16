#include <iostream>
#include <vector>
#include <map>

using namespace std;
typedef long long ll;

map<ll, ll> dp; //배열은 비효율적

ll fillDp(ll n, ll p, ll q) {
    if (dp[n]) //이미 값이 있음
        return dp[n];
    return dp[n] = fillDp(n / p, p, q) + fillDp(n / q, p, q);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, p, q;

    cin >> n >> p >> q;
    dp[0] = 1;
    cout << fillDp(n, p, q);
}