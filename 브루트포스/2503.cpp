#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, pair<int, int>> answer;

pair<int, int> baseball(string ans_candi, string asked) {
    int strike = 0, ball = 0;
    for (int i = 0; i < 3; i++) {
        if (asked[i] == ans_candi[i]) //스트라이크
            strike++;
        else if (ans_candi.find(asked[i]) != string::npos) //볼
            ball++;
    }
    return make_pair(strike, ball);
}

bool isPromise(string cur_num) {
    for (const auto &ans:answer) {
        pair<int, int> result = baseball(cur_num, ans.first); //해당 조합 숫자야구 결과
        if (result.first != ans.second.first || result.second != ans.second.second) //불일치
            return false;
    }
    return true;
}

int main() {
    string num;
    int N, s, b;

    cin >> N;
    while (N--) {
        cin >> num >> s >> b;
        answer[num] = make_pair(s, b);
    }
    int result = 0;
    for (int i = 123; i <= 987; i++) {
        string cur = to_string(i);
        if (cur[0] == cur[1] || cur[0] == cur[2] || cur[1] == cur[2] || cur[1] == '0' || cur[2] == '0') //중복이거나 0
            continue;
        if (isPromise(cur))
            result++;
    }
    cout << result;
}