#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> port, dp;

int lis(int n) { //가장 긴 증가하는 부분 수열
    for (int i = 0; i < n; i++) {
        int pos = lower_bound(dp.begin(), dp.end(), port[i]) - dp.begin(); //위치
        if (pos == dp.size()) //제일 큰 수라면
            dp.push_back(port[i]);
        else
            dp[pos] = port[i];
    }
    return dp.size();
}

int main() {
    int n;

    cin >> n;
    port.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> port[i];
    cout<<lis(n);
}