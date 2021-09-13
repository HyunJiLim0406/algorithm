#include <iostream>

using namespace std;
typedef long long ll;
const ll MOD = 1e9;

int fib(int n) {
    if (n <= 1)
        return n;
    ll a = 0, b = 1, ans = 0;
    for (int i = 2; i <= n; i++) {
        ans = (a + b) % MOD;
        a = b;
        b = ans;
    }
    return ans;
}

int fibMi(int n) {
    ll a = 1, b = 0, ans = 0;
    for (int i = -1; i >= n; i--) {
        ll num = a - b;
        ans = abs(num) % MOD;
        if (num < 0) //음수였다면
            ans *= (-1);
        a = b;
        b = ans;
    }
    return ans;
}

int main() {
    int n, ans;

    cin >> n;
    if (n >= 0) //양수
        ans = fib(n);
    else //음수
        ans = fibMi(n);

    if (ans > 0)
        cout << 1 << '\n';
    else if (ans == 0)
        cout << 0 << '\n';
    else
        cout << -1 << '\n';
    cout << abs(ans);
}