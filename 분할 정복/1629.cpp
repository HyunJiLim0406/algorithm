#include <iostream>

using namespace std;

long long divide(long long A, long long B, long long C) {
    long long tmp;

    if (B == 1) //더이상 나눌 수 없음
        return A % C;
    else {
        if (B % 2 == 0) { //짝수 거듭제곱일 때
            tmp = divide(A, B / 2, C);
            return (tmp * tmp) % C;
        } else //홀수 거듭제곱일 때
            return (A * divide(A, B - 1, C)) % C;
    }
}

int main() {
    long long A, B, C;

    cin >> A >> B >> C;
    cout << divide(A, B, C);
}