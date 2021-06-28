#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int result = 0;
    string str1, str2;

    cin >> str1 >> str2;
    vector<vector<int>> dp(str1.size() + 1, vector<int>(str2.size() + 1));
    for (int i = 1; i <= str1.size(); i++) {
        for (int j = 1; j <= str2.size(); j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1; //연속한 문자열만 저장되도록
                result = max(result, dp[i][j]); //최댓값 갱신
            }
        }
    }
    cout << result;
}