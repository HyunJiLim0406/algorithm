#include <iostream>
#include <vector>

using namespace std;

vector<int> dp;

void fillDp(int B) { //1부터 B까지의 dp
    int cur_num = 1, cnt = 0;
    for (int i = 1; i <= B; i++) {
        dp[i] = dp[i - 1] + cur_num;
        cnt++;
        if (cnt == cur_num) {
            cnt = 0;
            cur_num++;
        }
    }
}

int main() {
    int A, B;

    cin >> A >> B;
    dp.assign(B + 1, 0);
    fillDp(B);
    cout << dp[B] - dp[A - 1];
}