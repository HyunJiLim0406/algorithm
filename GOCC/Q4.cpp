#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;
const int DIVISOR = 1000000007;

ll gcd(int a, int b) {
    int tmp, nx, ny;
    nx = a;
    ny = b;

    if (nx < ny)
        swap(nx, ny);
    while (ny != 0) {
        tmp = nx % ny;
        nx = ny;
        ny = tmp;
    }
    return ((a * b) / nx) % DIVISOR;
}

int main() {
    int T, N, X, Y;

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N >> X >> Y;
        ll div = gcd(X, Y); //최소 공배수
        ll start = pow(10, N - 1);
        start %= DIVISOR;
        ll end = pow(10, N) - 1;
        end %= DIVISOR;

        start = start / div; //start 보다 작은 최소 공배수
        end = end / div; //end 보다 작은 최소 공배수
        cout << end - start << '\n';
    }
}