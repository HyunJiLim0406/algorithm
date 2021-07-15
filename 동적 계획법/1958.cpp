#include <iostream>
#include <vector>

using namespace std;

int lcs(string str1, string str2, string str3) {
    int s1 = str1.size(), s2 = str2.size(), s3 = str3.size();
    vector<vector<vector<int>>> dp(s1 + 1, vector<vector<int>>(s2 + 1, vector<int>(s3 + 1)));
    for (int i = 1; i <= s1; i++) {
        for (int j = 1; j <= s2; j++) {
            for (int k = 1; k <= s3; k++) {
                if (str1[i - 1] == str2[j - 1] && str2[j - 1] == str3[k - 1]) //문자가 전부 일치
                    dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                else //하나라도 불일치
                    dp[i][j][k] = max(dp[i - 1][j][k], max(dp[i][j - 1][k], dp[i][j][k - 1]));
            }
        }
    }
    return dp[s1][s2][s3];
}

int main() {
    vector<string> str(3);
    for (int i = 0; i < 3; i++)
        cin >> str[i];
    cout << lcs(str[0], str[1], str[2]);
}