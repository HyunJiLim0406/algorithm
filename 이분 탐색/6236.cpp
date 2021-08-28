#include <iostream>
#include <vector>

using namespace std;
const int MAX = 10000;

vector<int> cost;

int withdrawCnt(int money) {
    int size = cost.size(), cnt = 1, cur_money = money;
    for (int i = 0; i < size; i++) {
        if (cur_money >= cost[i])
            cur_money -= cost[i];
        else {
            cnt++;
            cur_money = money - cost[i];
        }
    }
    return cnt;
}

int lowerSearch(int left, int right, int M) {
    while (left <= right) {
        int mid = (left + right) / 2;
        if (withdrawCnt(mid) <= M)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return left;
}

int main() {
    int N, M, left = 0, right = 0;

    cin >> N >> M;
    cost.assign(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> cost[i];
        left = max(left, cost[i]);
        right += cost[i];
    }
    cout << lowerSearch(left, right, M);
}