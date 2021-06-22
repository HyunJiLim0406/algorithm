#include <iostream>
#include <string>

using namespace std;

int N;
bool is_found;
string str;

bool isPromise(int len) {
    for (int i = 0; i < (len + 1) / 2; i++) { //가능한 모든 길이로 자르면서 비교하기
        if (str.substr(len - (2 * i) - 1, i + 1) == str.substr(len - i, i + 1))
            return false;
    }
    return true;
}

void backtracking(int len) {
    if (len == N) { //문자열의 길이가 N이면
        is_found = true;
        return;
    }
    string tmp = str;
    for (int i = 1; i <= 3; i++) { //1~3까지 넣어보기
        str += to_string(i);
        if (isPromise(len)) //좋은 수열이라면
            backtracking(len + 1);
        if (is_found)
            return;
        str = tmp;
    }
}

int main() {
    cin >> N;
    backtracking(0);
    cout << str;
}