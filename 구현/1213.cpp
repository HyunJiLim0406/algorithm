#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    bool is_possible = true, is_mid = false; //펠린드롬 가능 여부, 가운데 글자(홀수) 존재 여부
    string input, result;
    char ch;
    vector<int> cnt(26);

    cin >> input;
    for (char c : input) //카운트
        cnt[c - 'A']++;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] % 2 == 0 || !is_mid) { //짝수개거나 가운데 글자가 없을 때
            for (int j = 0; j < cnt[i] / 2; j++) //절반만큼 더해주기
                result += (i + 'A');
            if (cnt[i] % 2 == 1) { //가운데 글자로 사용해야 함
                is_mid = true;
                ch = i + 'A';
            }
        } else { //펠린드롬 만들기 불가능
            is_possible = false;
            break;
        }
    }
    if (is_possible) {
        cout << result; //앞부분 출력
        if (is_mid) //가운데 글자 있다면(홀수) 출력
            cout << ch;
        reverse(result.begin(), result.end()); //뒤집기
        cout << result; //뒷부분 출력
    } else
        cout << "I'm Sorry Hansoo";
}