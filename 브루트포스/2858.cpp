#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int R, B;

    cin >> R >> B;
    int tot_tile = R + B;
    int line = sqrt(tot_tile);
    for (int i = 1; i <= line; i++) {
        if (tot_tile % i) //i로 나누어 떨어지지 않으면 고려할 필요 없음
            continue;
        int w = i, l = tot_tile / i;
        if (2 * (w + l - 2) == R) { //가장자리에 필요한 타일 수 세기
            cout << l << ' ' << w;
            break;
        }
    }
}