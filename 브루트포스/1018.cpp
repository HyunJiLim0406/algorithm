#include <iostream>
using namespace std;

int main() {
    int N, M, i, j, a, b, fix, min_fix = 65;

    cin >> N >> M;
    char** panel = new char* [N];
    for (i = 0; i < N; i++)
        panel[i] = new char[M];
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            cin >> panel[i][j];
        }
    }
    for (i = 0; i <= N - 8; i++) { //8x8 만들 수 있는지 봐야함
        for (j = 0; j <= M - 8; j++) {
            fix = 0;
            for (a = i; a < i + 8; a++) {
                for (b = j; b < j + 8; b++) {
                    if (((a + b) % 2 == 0) && (panel[a][b] == 'B')) //B를 W로 바꿈
                        fix++;
                    if (((a + b) % 2 == 1) && (panel[a][b] == 'W')) //W를 B로 바꿈
                        fix++;
                }
            }
            if (fix > 32) //바꾸고 보니 반대로 바꾸는게 더 나을듯
                fix = 64 - fix;
            if (min_fix > fix) //지금까지 바꾼 것 중에 제일 낫나?
                min_fix = fix;
        }
    }
    cout << min_fix << endl;
}