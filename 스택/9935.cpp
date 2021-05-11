#include <iostream>
#include <stack>
#include <deque>
#include <string>

using namespace std;

int main() {
    string input, key;
    deque<char> s; //그냥 스택인데 출력 때문에 덱으로 선언

    cin >> input >> key;
    for (int i = 0; i < input.size(); i++) {
        stack<char> tmp;
        s.push_front(input[i]); //일단 넣어보고
        int idx = key.size() - 1; //key의 맨 마지막 글자 위치
        while ((idx >= 0) && (!s.empty()) && (s.front() == key[idx])) { //key와 일치하는 문자열이 있다면
            tmp.push(s.front());
            s.pop_front();
            idx--;
        }
        if (idx >= 0) { //key와 일치하는 문자열이 아니었다면 tmp에 있던 것들 다시 넣기
            while (!tmp.empty()) {
                s.push_front(tmp.top());
                tmp.pop();
            }
        }
    }
    if (s.empty()) //비어있는지 확인
        cout << "FRULA";
    else { //출력
        while (!s.empty()) {
            cout << s.back();
            s.pop_back();
        }
    }
}