#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int N, C;
vector<ll> house;

bool isInstall(ll dist) { //이 거리로 설치할 수 있는지 확인
    int cnt = 1;
    ll pos = house[0];

    for (int i = 1; i < house.size(); i++) {
        if ((house[i] - pos) >= dist) {
            cnt++;
            pos = house[i];
        }
        if (cnt == C)
            return true;
    }
    return false;
}

ll upperSearch(ll left, ll right) {
    while (left <= right) {
        ll mid = (left + right) / 2;
        if (!isInstall(mid))
            right = mid - 1;
        else if(isInstall(mid)) //else로 처리할 수 있지만 lower랑 비교하기 위해 유지
            left = mid + 1;
    }
    return right;
}

int main() {
    ll input;

    cin >> N >> C;
    for (int i = 0; i < N; i++) {
        cin >> input;
        house.push_back(input);
    }
    sort(house.begin(), house.end());

    cout << upperSearch(1, house[house.size() - 1]);
}