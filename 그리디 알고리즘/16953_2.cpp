#include <iostream>

using namespace std;

int main() {
    int A, B;

    cin >> A >> B;
    int cnt = 1;
    while (B != 0) { //모든 구간에서 B는 짝수거나 1로 끝나는 숫자
        if (B == A) { //A에 도달했다면 cnt 출력
            cout << cnt;
            return 0;
        }
        if (B % 2 == 0) //B가 짝수이면 그 이전 상태는 B/2
            B /= 2;
        else if (B % 10 == 1) //B가 1로 끝나면 그 이전 상태는 B/10
            B /= 10;
        else { //둘 다 아니면 A로 만들 수 없음
            cout << -1;
            return 0;
        }
        cnt++;
    }
    cout << -1;
}