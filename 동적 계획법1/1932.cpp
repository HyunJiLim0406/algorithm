#include <iostream>
#include <algorithm>
using namespace std;

int triangle[501][501];

int tri_sum(int n) {
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (j == 1)
                triangle[i][j] += triangle[i - 1][j]; //왼쪽 끝일 때
            else if (j == i)
                triangle[i][j] += triangle[i - 1][j - 1]; //오른쪽 끝일 때
            else
                triangle[i][j] += max(triangle[i - 1][j - 1], triangle[i - 1][j]);
        }
    }
    int max = triangle[n][1]; //최대값 찾기
    for (int i = 2; i <= n; i++) {
        if (triangle[n][i] > max)
            max = triangle[n][i];
    }
    return max;
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