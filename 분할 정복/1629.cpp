#include <iostream>

using namespace std;

typedef long long ll;

ll divide(ll A, ll B, ll C) {
    ll tmp;

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
    ll A, B, C;

    cin >> A >> B >> C;
    cout << divide(A, B, C);
}