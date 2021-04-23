#include <iostream>
#include <algorithm>

using namespace std;

int finalYear(int M, int N) { //최소공배수로 구한 마지막 해
    int tmp, a, b;

    a = M, b = N;
    if (a < b)
        swap(a, b);
    while (b != 0) {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return (M * N) / a;
}

int calender(int final_year, int M, int N, int x, int y) {
    int nx, ny;

    nx = x;
    ny = x;
    for (int i = nx; i <= final_year; i += M) { //M 만큼 건너 뛰기
        if (ny > N)
            ny %= N;
        if (ny == 0)
            ny += N;

        if (ny == y) //종료 조건
            return i;
        ny += M;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T, M, N, x, y;

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> M >> N >> x >> y;
        cout << calender(finalYear(M, N), M, N, x, y) << '\n';
    }
}