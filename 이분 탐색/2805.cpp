#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int N, M;
vector<ll> tree;

ll cntTree(ll length) { //총 몇 m의 나무가 나오는지 계산
    ll cnt = 0;

    for (int i = 0; i < tree.size(); i++) {
        ll tmp = tree[i] - length;
        if (tmp > 0)
            cnt += tmp;
    }
    return cnt;
}

ll upperSearch(ll left, ll right) {
    while (left <= right) {
        ll mid = (left + right) / 2;
        ll trees = cntTree(mid);
        if (trees < M)
            right = mid - 1;
        else if (trees >= M) //else로 처리할 수 있지만 lower랑 비교하기 위해 유지
            left = mid + 1;
    }
    return right;
}

int main() {
    ll input;

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> input;
        tree.push_back(input);
    }
    sort(tree.begin(), tree.end());

    cout << upperSearch(0, tree[tree.size() - 1]);
}