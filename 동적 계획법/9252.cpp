#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> dp;

string findLCS(string a, string b) {
    stack<char> s;
    string result = "";
    int row = a.size() + 1; //행
    int col = b.size() + 1; //열
    for (int i = 1; i < row; i++) {
        for (int j = 1; j < col; j++) {
            if (a[i - 1] == b[j - 1]) //두 문자가 같음
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else //두 문자가 다름
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    row--;
    col--;
    while ((row > 0) && (col > 0)) { //둘 중 하나라도 0이 된다면 break
        int num = dp[row][col];
        if (a[row - 1] == b[col - 1]) { //두 문자가 같으면 공통 수열의 문자, 대각선 위로 올라감
            s.push(a[row - 1]); //스택에 투입
            row--;
            col--;
        } else if (num == dp[row - 1][col]) //두 문자가 다르고, 위로 올라감
            row--;
        else //두 문자가 다르고, 왼쪽으로 감
            col--;
    }
    while (!s.empty()) { //스택 결과 빼기
        result += s.top();
        s.pop();
    }
    return result;
}

int main() {
    string a, b, LCS;

    cin >> a >> b;
    dp.assign(a.size() + 1, vector<int>(b.size() + 1, 0));
    LCS = findLCS(a, b);
    cout << LCS.size() << '\n' << LCS;
}