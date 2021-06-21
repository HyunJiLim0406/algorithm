#include <iostream>
#include <string>

using namespace std;

int main() {
    int zero_cnt = 0, one_cnt = 0;
    string input;

    cin >> input;
    char cur = '2';
    for (int i = 0; i < input.size(); i++) {
        if (cur != input[i]) { //연속된 수가 아닐 때
            cur = input[i];
            (input[i] == '0') ? zero_cnt++ : one_cnt++;
        }
    }
    cout << min(zero_cnt, one_cnt); //둘 중 더 작은 수
}