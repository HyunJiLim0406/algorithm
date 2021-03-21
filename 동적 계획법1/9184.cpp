#include <iostream>

using namespace std;

int w_func(int a, int b, int c) { //재귀를 약간 써도 시간초과가 생기지는 않는가 보다...
    int w[21][21][21] = {0};

    if (a <= 0 || b <= 0 || c <= 0)
        return 1;
    if (a > 20 || b > 20 || c > 20) {
        a = 20;
        b = 20;
        c = 20;
    }
    for (int i = 0; i <= a; i++) {
        for (int j = 0; j <= b; j++) {
            for (int k = 0; k <= c; k++) {
                if (i <= 0 || j <= 0 || k <= 0)
                    w[i][j][k] = 1;
                else if (i < j && j < k)
                    w[i][j][k] = w[i][j][k - 1] + w[i][j - 1][k - 1] - w[i][j - 1][k];
                else
                    w[i][j][k] = w[i - 1][j][k] + w[i - 1][j - 1][k] + w[i - 1][j][k - 1] - w[i - 1][j - 1][k - 1];
            }
        }
    }
    return w[a][b][c];
}

int main() {
    int a, b, c;

    while (true) {
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1)
            break;
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w_func(a, b, c) << '\n';
    }
}