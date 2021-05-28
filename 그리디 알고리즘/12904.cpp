#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string S, T;

    cin >> S >> T;
    while (S != T) { //S와 T가 다르다면
        if (S.size() > T.size()) { //T의 길이가 S보다 짧아졌다면 S가 될 수 없음
            cout << 0;
            return 0;
        }
        char last_c = T[T.size() - 1]; //T의 마지막 문자
        T.erase(T.size() - 1); //어떤 문자여도 지워짐
        if (last_c == 'B') //B였다면 reverse
            reverse(T.begin(), T.end());
    }
    cout << 1; //성공
}