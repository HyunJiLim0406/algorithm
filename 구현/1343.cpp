#include <iostream>

using namespace std;

int strCnt(string str, int idx) {
    int cnt = 0;
    for (int i = idx; i < str.size(); i++) {
        if (str[i] == '.')
            break;
        cnt++;
    }
    return cnt;
}

int main() {
    string input, result;
    cin >> input;
    for (int i = 0; i < input.size(); i++) {
        if (input[i] == '.') {
            result += ".";
            continue;
        }
        int cnt = strCnt(input, i);
        if (cnt >= 4) {
            result += "AAAA";
            i += 3;
        } else if (cnt >= 2) {
            result += "BB";
            i += 1;
        } else {
            cout << -1;
            return 0;
        }
    }
    cout << result;
}