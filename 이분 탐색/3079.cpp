#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

vector<ll> line;

bool isPos(int N, int M, ll num) {
    ll cnt = 0;
    for (int i = 0; i < N; i++)
        cnt += (num / line[i]);
    return cnt >= M;
}

ll lowerSearch(int N, int M, ll left, ll right) {
    while (left <= right) {
        ll mid = (left + right) / 2;
        if (isPos(N, M, mid))
            right = mid - 1;
        else
            left = mid + 1;
    }
    return left;
}

int main() {
    int N, M;
    ll min_time = 1e9;

    cin >> N >> M;
    line.assign(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> line[i];
        min_time = min(min_time, line[i]);
    }
    cout << lowerSearch(N, M, 0, min_time * M);
}