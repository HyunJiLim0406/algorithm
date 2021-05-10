#include <iostream>
#include <utility>
#include <cmath>
#include <vector>

using namespace std;

int recurZ(int N, int r, int c, int num, pair<int, int> p) {
    if (N == 0) //방문 순서 출력
        return num;
    int mul = pow(2, N - 1); //2^3 * 2^3 이라면 4씩 좌표가 증가할 것
    vector<pair<int, int>> pos; //각 사분면의 좌표
    for (int i = p.first; i <= (p.first + mul); i += mul) {
        for (int j = p.second; j <= (p.second + mul); j += mul)
            pos.push_back(make_pair(i, j));
    }
    for (int i = 3; i >= 0; i--) { //뒤에서부터 일치하는 해당하는 사분면 찾기
        if ((r >= pos[i].first) && (c >= pos[i].second))
            return recurZ(N - 1, r, c, num + (pow(4, N - 1) * i), pos[i]);
    }
    return 0;
}

int main() {
    int N, r, c;

    cin >> N >> r >> c;
    cout << recurZ(N, r, c, 0, make_pair(0, 0));
}