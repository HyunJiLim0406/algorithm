#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool is_found;

void backward(string S, string T) {
    if (S == T) { //S와 T가 같으면 is_found를 true로
        is_found = true;
        return;
    }
    if ((S.size() > T.size()) || is_found) //T의 길이가 S보다 짧거나, is_found가 true면 리턴
        return;
    string tmp = T; //임시저장
    if (T[0] == 'B') { //첫글자가 B라면 2번 연산 가능
        reverse(T.begin(), T.end());
        backward(S, T.erase(T.size() - 1));
    }
    if (T[T.size() - 1] == 'A') //마지막 글자가 A라면 1번 연산 가능
        backward(S, tmp.erase(tmp.size() - 1));
}

int main() {
    string S, T;

    cin >> S >> T;
    backward(S, T);
    cout << is_found;
}