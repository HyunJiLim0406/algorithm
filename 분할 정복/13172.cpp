#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
const int DIVISOR = 1000000007;

ll gcd(ll a, ll b) { //유클리드 호제법
    ll tmp, na = a, nb = b;
    if (na < nb)
        swap(na, nb);
    while (nb != 0) {
        tmp = na % nb;
        na = nb;
        nb = tmp;
    }
    return na;
}

ll calc(ll num, int mul) { //분할 정복
    if (mul == 0)
        return 1;
    else if (mul % 2 == 0) //짝수일 때
        return calc((num * num) % DIVISOR, mul / 2) % DIVISOR;
    else //홀수일 때
        return (num * calc(num, mul - 1)) % DIVISOR;
}

ll calcModular(ll a, ll b) {
    ll reverse_b = calc(b, DIVISOR - 2) % DIVISOR; //b의 역원
    return (a * reverse_b) % DIVISOR;
}

int main() {
    int M;
    ll a, b, result = 0;

    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> b >> a;
        ll div = gcd(a, b); //기약 분수로 만들기
        a /= div;
        b /= div;
        result += calcModular(a, b); //모듈러 연산
        result %= DIVISOR;
    }
    cout << result;
}