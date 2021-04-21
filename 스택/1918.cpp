#include <iostream>
#include <stack>
#include <string>

using namespace std;

int score(char ch) { //우선 순위
    switch (ch) {
        case '(': case ')':
            return 3;
        case '+': case '-':
            return 2;
        case '*': case '/':
            return 1;
        default:
            return 0;
    }
}

int main() {
    string str;
    stack<char> s;

    cin>>str;
    for(int i=0;i<str.size();i++){
        switch(str[i]){
            case '(': //왼쪽 괄호는 무조건 스택에
                s.push(str[i]);
                break;
            case ')':
                while(s.top()!='('){ //왼쪽 괄호 만날 때 까지 스택 출력
                    cout<<s.top();
                    s.pop();
                }
                s.pop();
                break;
            case '+': case '-': case '*': case '/': //str[i]보다 우선순위가 높거나 같은 것 출력
                while(!s.empty()&&(score(s.top())<=score(str[i]))){
                    cout<<s.top();
                    s.pop();
                }
                s.push(str[i]);
                break;
            default: //문자는 바로 출력
                cout<<str[i];
                break;
        }
    }
    while(!s.empty()){ //스택에 남은 연산자 출력
        cout<<s.top();
        s.pop();
    }
}