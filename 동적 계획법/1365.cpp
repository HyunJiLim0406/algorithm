#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> input;

int lis() {
    vector<int> dp;
    for (int i = 0; i < input.size(); i++) {
        int pos = lower_bound(dp.begin(), dp.end(), input[i]) - dp.begin();
        if (pos == dp.size())
            dp.push_back(input[i]);
        dp[pos] = input[i];
    }
    return dp.size();
}

int main() {
    int N;

    cin >> N;
    input.assign(N, 0);
    for (int i = 0; i < N; i++)
        cin >> input[i];
    cout << N - lis();
}