
#include <iostream>
#include <algorithm>
using namespace std;

pair<long long, long long> binomial(long long n) {
    int two_cnt = 0, five_cnt = 0;

    for (long long i = 2; i <= n; i *= 2)
        two_cnt += n / i;
    for (long long i = 5; i <= n; i *= 5)
        five_cnt += n / i;
    return pair<long long, long long>(two_cnt, five_cnt);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n, m;

    cin >> n >> m;
    pair<long long, long long>p1 = binomial(n); //n!
    pair<long long, long long>p2 = binomial(m); //m!
    pair<long long, long long>p3 = binomial(n - m); //(n-m)!
    long long two = p1.first - p2.first - p3.first;
    long long five = p1.second - p2.second - p3.second;
    cout << min(two, five);
}