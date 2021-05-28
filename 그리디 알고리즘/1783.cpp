#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N, M;

    cin >> N >> M;
    if (N == 1) //세로 길이가 1이면 못 움직임
        cout << 1;
    else if (N == 2) //세로 길이가 2면 (2, 3)번 방법으로만 이동(최대 4번)
        cout << min(4, (M + 1) / 2);
    else if (M < 7) //가로 길이가 7보다 작으면 (1, 4)번 방법으로만 이동(최대 4번)
        cout << min(4, M);
    else //(2, 3)번 한번 이동하고 나머지는 (1, 4)번
        cout << M - 2;
}