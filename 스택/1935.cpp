#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() { //'A'-'0' = 17, 'Z'-'0' = 42
    stack<double> s;
    string str;
    double arr[26], num[2];
    int N;

    cin >> N;
    cin >> str;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    for (int i = 0; i < str.size(); i++) {
        if ((str[i] >= 'A') && (str[i] <= 'Z')) //문자면 숫자로 바꿔서 스택에 넣기
            s.push(arr[(str[i] - '0') - 17]);
        else {
            for (int i = 1; i >= 0; i--) { //계산할 숫자 2개 빼기
                num[i] = s.top();
                s.pop();
            }
            switch (str[i]) { //사칙연산
                case '+':
                    s.push(num[0] + num[1]);
                    break;
                case '-':
                    s.push(num[0] - num[1]);
                    break;
                case '*':
                    s.push(num[0] * num[1]);
                    break;
                case '/':
                    s.push(num[0] / num[1]);
                    break;
            }
        }
    }
    cout << fixed;
    cout.precision(2);
    cout << s.top();
}