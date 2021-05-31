#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;

ll calcLen(int n) { //이 숫자까지의 길이
    ll res = 0, mul = 10;
    int idx = 1;
    while (true) { //한자리씩 증가. 10, 100, ...
        if (n >= (mul - 1)) {
            res += 9 * pow(10, idx - 1) * idx;
            idx++;
            mul *= 10;
        } else { //10 ~ 20 자릿수 계산
            mul /= 10;
            res += (n - (mul - 1)) * idx;
            break;
        }
    }
    return res;
}

int main() {
    int N, k;

    cin >> N >> k;
    if (k > calcLen(N)) { //범위를 벗어난 수
        cout << -1;
        return 0;
    }
    int left = 1, right = N;
    while (left <= right) { //upper-bound
        int mid = (left + right) / 2;
        ll len = calcLen(mid);
        if (len < k)
            left = mid + 1;
        else
            right = mid - 1;
    }
    string str = to_string(right + 1);
    cout << str[str.size() - (calcLen(right + 1) - k) - 1];
}