#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<bool>> is_palindrome;

void findPalindrome(string str) {
    int n = str.size();
    is_palindrome.assign(n, vector<bool>(n));
    for (int gap = 0; gap < n; gap++) {
        for (int start = 0; start < n - gap; start++) {
            int end = start + gap;
            if (str[start] == str[end]) //양 끝의 숫자가 같으면 true(일단)
                is_palindrome[start][end] = true;
            if (gap >= 2 && !is_palindrome[start + 1][end - 1]) //gap이 2 이상이면 그 안쪽도 팰린드롬인지 확인
                is_palindrome[start][end] = false;
        }
    }
}

int fillDp(string str) {
    int n = str.size();
    vector<int> dp(n + 1);
    for (int i = 1; i <= n; i++) {
        dp[i] = 1e9; //초기화
        for (int j = 1; j <= i; j++) {
            if (is_palindrome[i - j][i - 1]) //ABACABA의 2번째 A일 때, A/B/A([2][2])와 ABA([0][2]) 체크
                dp[i] = min(dp[i], dp[i - j] + 1);
        }
    }
    return dp[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;
    findPalindrome(str);
    cout << fillDp(str);
}