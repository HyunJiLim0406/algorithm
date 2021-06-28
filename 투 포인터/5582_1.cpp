#include <iostream>
#include <string>

using namespace std;

int main() {
    string str1, str2, tmp;

    cin >> str1 >> str2;
    int l = 0, r = 0, len = 0;
    while (l < str1.size() && r < str1.size()) {
        if (l <= r) {
            tmp = str1.substr(l, r - l + 1); //문자열 자르기
            if (str2.find(tmp) != string::npos) { //존재한다면 오른쪽 포인터 이동
                len = max(len, r - l + 1);
                r++;
            } else //존재하지 않는다면 왼쪽 포인터 이동
                l++;
        } else
            r++;
    }
    cout << len;
}