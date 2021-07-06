#include <iostream>
#include <algorithm>

using namespace std;

int triangle[501][501];

int tri_sum(int n) { //맨아래에서 두번째부터 올라가며 계산
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            triangle[i][j] += max(triangle[i + 1][j], triangle[i + 1][j + 1]);
        }
    }
    return triangle[1][1];
}

int main() {
    int n;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++)
            cin >> triangle[i][j];
    }
    cout << tri_sum(n);
}