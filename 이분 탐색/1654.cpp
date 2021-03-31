#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int K, N;
vector<ll> wire;

ll cntWire(ll length) { //랜선이 총 몇개가 나오는지 계산
    ll cnt = 0;

    for (int i = 0; i < wire.size(); i++)
        cnt += (wire[i] / length);
    return cnt;
}

ll upperSearch(ll left, ll right) { //upper_bound를 찾는 문제와 같음.
    while (left <= right) {
        ll mid = (left + right) / 2;
        ll wires = cntWire(mid);
        if (wires < N)
            right = mid - 1;
        else if (wires >= N) //else로 처리할 수 있지만 lower랑 비교하기 위해 유지
            left = mid + 1;
    }
    return right;
}

int main() {
    ll input;

    cin >> K >> N;
    for (int i = 0; i < K; i++) {
        cin >> input;
        wire.push_back(input);
    }
    sort(wire.begin(), wire.end()); //정렬

    cout << upperSearch(1, wire[wire.size() - 1]); //제일 큰걸로!
}