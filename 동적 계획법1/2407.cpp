#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<vector<string>> dp;

vector<int> toInt(string s) { //뒤에서부터 숫자로 바꿔서 벡터에 넣기
    vector<int> v;
    for (int i = s.size() - 1; i >= 0; i--) {
        v.push_back(s[i] - '0');
    }
    return v;
}

string calc(vector<int> v1, vector<int> v2) {
    stack<int> s;
    string result = "";
    bool flag = false; //올림
    for (int i = 0; i < v1.size(); i++) {
        int sum = v1[i] + v2[i];
        if (flag) //올림이 있었다면 1 더하기
            sum++;
        if (sum > 9) { //10이상이면 올림 처리
            sum %= 10;
            flag = true;
        } else
            flag = false;
        s.push(sum); //스택에 넣기
    }
    while (s.top() == 0) //0으로 시작하지 않도록
        s.pop();
    while (!s.empty()) { //결과에 넣기
        result += to_string(s.top());
        s.pop();
    }
    return result;
}

string combi(int n, int m) {
    vector<int> num1, num2;
    if (m > (n / 2))
        m = n - m;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; (j <= i) && (j <= m); j++) {
            if (i == j || j == 0) //양 끝
                dp[i][j] = "1";
            else {
                num1 = toInt(dp[i - 1][j - 1]); //1234라면 4321로 저장
                num2 = toInt(dp[i - 1][j]); //45이라면 54로 저장
                int len = max(num1.size(), num2.size()) + 1; //더 긴 벡터의 길이에 +1, 여기서는 5(마지막 올림 가능성 때문에 0을 하나 더 붙여줌)
                while (num1.size() != len) //43210이 될 것
                    num1.push_back(0);
                while (num2.size() != len) //54000이 될 것
                    num2.push_back(0);
                dp[i][j] = calc(num1, num2); //더하고 string으로 바꿔서 넣기
            }
        }
    }
    return dp[n][m];
}

int main() {
    int n, m;
    cin >> n >> m;
    dp.assign(n + 1, vector<string>(n + 1));
    cout << combi(n, m);
}