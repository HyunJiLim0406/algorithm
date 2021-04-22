#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) { //유클리드 호제법
    ll tmp;

    if (a < b) {
        tmp = a;
        a = b;
        b = tmp;
    }
    while (b != 0) {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int main() {
    ll N, S, input;
    vector<ll> v;

    cin >> N >> S;
    for (int i = 0; i < N; i++) { //차이 계산
        cin >> input;
        v.push_back(abs(S - input));
    }
    ll result = v[0];
    for (int i = 1; i < N; i++) //연속적으로 최대공약수 계산
        result = gcd(result, v[i]);
    cout << result;
}