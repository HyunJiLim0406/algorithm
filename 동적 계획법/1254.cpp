#include <iostream>
#include <vector>

using namespace std;

vector<vector<bool>> dp;

int fillDp(string str) { //펠린드롬 dp
    int size = str.size();
    for (int gap = 0; gap < size; gap++) {
        for (int start = 0; start < size - gap; start++) {
            int end = start + gap;
            if (str[start] == str[end])
                dp[start][end] = true;
            if (gap > 2 && !dp[start + 1][end - 1])
                dp[start][end] = false;
        }
    }
    for (int i = 0; i < size; i++) { //맨마지막 문자부터 시작하는 가장 긴 펠린드롬
        if (dp[i][size - 1])
            return i;
    }
    return -1;
}

int main() {
    string str;

    cin >> str;
    dp.assign(str.size(), vector<bool>(str.size()));
    cout << str.size() + fillDp(str);
}