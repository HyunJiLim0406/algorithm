#include <iostream>
#include <algorithm>
using namespace std;

int house[1000][3];

int findMin(int a, int b, int c) { //인자 3개 min 함수
    if (a < b) {
        if (a < c)
            return a;
        else
            return c;
    }
    else {
        if (b < c)
            return b;
        else
            return c;
    }
}

int coloring(int num) {
    for (int i = 1; i < num; i++) {
        //i번째 집을 R로 칠할 때 i-1번째 집은 G나 B일 것임. 그 이전 집이 G인 경우와 B인 경우 중 더 작은 것과 i번째 집의 R을 더하면 됨
        house[i][0] += min(house[i - 1][1], house[i - 1][2]); //R로 색칠
        house[i][1] += min(house[i - 1][0], house[i - 1][2]); //G로 색칠
        house[i][2] += min(house[i - 1][1], house[i - 1][0]); //B로 색칠
    }
    return findMin(house[num - 1][0], house[num - 1][1], house[num - 1][2]); //RGB중 가장 작은 애가 최소값임
}

int main() {
    int N;

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++)
            cin >> house[i][j];
    }
    cout << coloring(N);
}