#include <iostream>

using namespace std;

typedef long long ll;
const ll DIVISOR = 1000000007;

ll fact(ll num) { //팩토리얼 계산
    ll res = 1;

    for (ll i = 1; i <= num; i++) {
        res *= i;
        res %= DIVISOR;
    }
    return res;
}

ll divide(ll A, ll B) {
    ll tmp;

    if (B == 1) //더이상 나눌 수 없음
        return A % DIVISOR;
    else {
        if (B % 2 == 0) { //짝수 거듭제곱일 때
            tmp = divide(A, B / 2);
            return (tmp * tmp) % DIVISOR;
        } else //홀수 거듭제곱일 때
            return (A * divide(A, B - 1)) % DIVISOR;
    }
}

int main() {
    ll N, K;

    cin >> N >> K;
    ll numerator = fact(N); //분자
    ll denominator = (fact(K) * fact(N - K)) % DIVISOR; //분모
    denominator = divide(denominator, DIVISOR - 2); //페르마의 소정리로 구한 역원
    cout << (numerator * denominator) % DIVISOR;
}