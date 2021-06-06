#include <iostream>
#include <vector>

using namespace std;

bool isIn(int x, int y, int cx, int cy, int r) { //각 점이 행성 안에 있는지 확인
    int nx = abs(x - cx);
    int ny = abs(y - cy);
    return (nx * nx) + (ny * ny) < (r * r);
}

int main() {
    int T, x[2], y[2], n, cx, cy, r;

    cin >> T;
    while (T--) {
        int cnt = 0;
        cin >> x[0] >> y[0] >> x[1] >> y[1] >> n;
        for (int i = 0; i < n; i++) {
            int local_cnt = 0;
            cin >> cx >> cy >> r;
            for (int j = 0; j < 2; j++) {
                if (isIn(x[j], y[j], cx, cy, r)) //행성안에 있다면 ++
                    local_cnt++;
            }
            if (local_cnt == 1) //둘 중 하나만 행성 안에 있어야 함
                cnt++;
        }
        cout << cnt << '\n';
    }
}