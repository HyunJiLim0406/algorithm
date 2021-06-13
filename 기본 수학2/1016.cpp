#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

vector<bool> not_squared;

void eratos(ll min_num, ll max_num) {
    ll line = (ll) sqrt(max_num); //최댓값의 제곱근
    for (ll i = 2; i <= line; i++) {
        ll pow = i * i; //제곱수
        ll start = min_num / pow; //제곱수와 곱해서 처음으로 min_num과 같거나 커지게 만드는 수
        if (start * pow != min_num)
            start++;
        while (start * pow <= max_num) { //false 처리
            not_squared[start * pow - min_num] = false;
            start++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll min_num, max_num;

    cin >> min_num >> max_num;
    not_squared.assign(max_num - min_num + 1, true);
    eratos(min_num, max_num);
    ll cnt = 0;
    for (ll i = 0; i <= max_num - min_num; i++) {
        if (not_squared[i])
            cnt++;
    }
    cout << cnt;
}