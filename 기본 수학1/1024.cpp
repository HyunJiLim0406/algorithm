#include <iostream>

using namespace std;

int main() {
    int N, L, result = -1, len;

    cin >> N >> L;
    for (int i = L; i <= 100; i++) { //X+1 + X+2 + ... + X+L
        int sum = i * (i + 1) / 2; //1+2+...+L
        if ((N - sum) % i == 0) {
            result = (N - sum) / i + 1; //X+1
            len = i; //수열의 길이
            break;
        }
    }
    if (result < 0) //시작숫자가 0 이상이어야 함
        cout << -1;
    else {
        for (int i = 0; i < len; i++)
            cout << result++ << ' ';
    }
}