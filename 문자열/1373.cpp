#include <iostream>
#include <stack>
#include <cmath>
#include <string>

using namespace std;

int main() {
    string str;
    stack<int> s;
    int tmp = 0;

    cin >> str;
    for (int i = str.size() - 1; i >= 0; i--) {
        int idx = str.size() - i - 1;

        tmp += ((str[i] - '0') * pow(2, (idx % 3)));
        if ((idx % 3 == 2) || idx == str.size() - 1) { //3개 단위로 끊기
            s.push(tmp);
            tmp = 0; //초기화
        }
    }
    while (!s.empty()) { //역순 출력
        cout << s.top();
        s.pop();
    }
}