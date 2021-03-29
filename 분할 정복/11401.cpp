#include <iostream>

using namespace std;

const long long DIVISOR = 1000000007;

long long fact(long long num) { //팩토리얼 계산
    long long res = 1;

    for (long long i = 1; i <= num; i++) {
        res *= i;
        res %= DIVISOR;
    }
    return res;
}

long long divide(long long A, long long B) {
    long long tmp;

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
    long long N, K;

    cin >> N >> K;
    long long numerator = fact(N); //분자
    long long denominator = (fact(K) * fact(N - K)) % DIVISOR; //분모
    denominator = divide(denominator, DIVISOR - 2); //페르마의 소정리로 구한 역원
    cout << (numerator * denominator) % DIVISOR;
}