#include <iostream>
#include <vector>

using namespace std;
const int MAX_WEIGHT = 15001;

vector<vector<bool>> dp;

void fillDp(vector<int> &weight) {
    dp[0][0] = dp[0][weight[0]] = true; //초기화
    for (int i = 1; i < weight.size(); i++) {
        for (int j = 0; j < MAX_WEIGHT; j++) {
            dp[i][j] = dp[i - 1][j]; //추를 사용하지 않음
            if (dp[i - 1][j + weight[i]]) //구슬이 있는 쪽에 추 놓기
                dp[i][j] = true;
            if (dp[i - 1][abs(j - weight[i])]) //양쪽 어디에도 놓을 수 있음
                dp[i][j] = true;
        }
    }
}

int main() {
    int n, t, num;

    cin >> n;
    vector<int> weight(n);
    dp.assign(n, vector<bool>(MAX_WEIGHT));
    for (int i = 0; i < n; i++)
        cin >> weight[i];
    fillDp(weight);
    cin >> t;
    while (t--) {
        cin >> num;
        cout << ((dp[n - 1][num]) ? "Y " : "N ");
    }
}