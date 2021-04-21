#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    string str;
    stack<char> s;
    int result = 0;

    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(') //왼쪽 괄호는 스택에 쌓기
            s.push(str[i]);
        else { //오른쪽 괄호일 때
            s.pop();
            if (str[i - 1] == '(') //이전이 왼쪽 괄호였으면 레이저
                result += s.size();
            else //이전이 오른쪽 괄호였으면 쇠막대기의 끝
                result++;
        }
    }
    cout << result;
}