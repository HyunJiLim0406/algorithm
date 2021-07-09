#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int w, h, p, q, t;

    cin >> w >> h >> p >> q >> t;
    p += t;
    q += t;
    p %= (2 * w); //왕복
    q %= (2 * h); //왕복
    if (p > w) //범위
        p = 2 * w - p;
    if (q > h) //범위
        q = 2 * h - q;
    cout << p << ' ' << q;
}