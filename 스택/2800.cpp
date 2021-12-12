#include <iostream>
#include <stack>
#include <vector>
#include <set>

using namespace std;

set<string> expList(int n, string exp, vector<int> &checker) {
    set<string> list;
    for (int bit = 0; bit < (1 << n) - 1; bit++) { //가능한 모든 경우의 수
        string tmp;
        for (int j = 0; j < exp.size(); j++) {
            if (checker[j] != -1 && !(bit & (1 << checker[j]))) //괄호인데 이번에 포함되지 않는다면 무시
                continue;
            tmp += exp[j];
        }
        list.insert(tmp);
    }
    return list;
}

int main() {
    string exp;
    stack<int> s;

    cin >> exp;
    vector<int> checker(exp.size(), -1);
    int idx = 0;
    for (int i = 0; i < exp.size(); i++) {
        if (exp[i] == '(') //왼쪽 괄호
            s.push(i);
        if (exp[i] == ')') { //오른쪽 괄호 발견시 왼쪽 괄호와 함께 인덱스 표시
            checker[s.top()] = checker[i] = idx++;
            s.pop();
        }
    }
    set<string> ans = expList(idx, exp, checker);
    for (auto str: ans)
        cout << str << '\n';
}