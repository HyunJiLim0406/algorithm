#include <iostream>
#include <string>

using namespace std;

int main() {
    string input, str = "UCPC";
    getline(cin, input);

    int idx = 0;
    while (idx < 4) {
        int pos = input.find(str[idx]); //문자 찾기
        if (pos == -1) { //없으면
            cout << "I hate UCPC";
            return 0;
        }
        input = input.substr(pos + 1); //찾은 문자 이후로 자르기
        idx++;
    }
    cout << "I love UCPC";
}