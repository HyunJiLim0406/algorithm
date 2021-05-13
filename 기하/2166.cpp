#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

vector<ll> x, y;

ll ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) { //ccw 알고리즘
    ll calc = (x1 * y2 + x2 * y3 + x3 * y1) - (y1 * x2 + y2 * x3 + y3 * x1);
    return calc;
}

int main() {
    int N;

    cin >> N;
    x.assign(N, 0);
    y.assign(N, 0);
    for (int i = 0; i < N; i++)
        cin >> x[i] >> y[i];
    double result = 0;
    for (int i = 2; i < N; i++) //(x[0], y[0])을 고정점으로
        result += (ccw(x[0], y[0], x[i - 1], y[i - 1], x[i], y[i])) / 2.0;
    result = abs(result); //절댓값 처리
    cout << fixed;
    cout.precision(1);
    cout << result;
}