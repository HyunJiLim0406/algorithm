#include <iostream>

using namespace std;

int main() {
    string str, min_num, max_num;

    cin >> str;
    int idx = 0;
    while (str.find('K', idx) != str.npos) {
        int new_idx = str.find('K', idx); //K의 위치
        if (new_idx == idx) { //K가 연속됐다면
            min_num += '5';
            max_num += '5';
            idx++;
            continue;
        }
        //첫번째 자리
        min_num += '1';
        max_num += '5';
        idx++;
        while (idx < new_idx) { //0 추가
            min_num += '0';
            max_num += '0';
            idx++;
        }
        //마지막 자리
        min_num += '5';
        max_num += '0';
        idx++;
    }
    //남은 M처리
    if (idx < str.size()) {
        min_num += '1';
        max_num += '1';
        idx++;
    }
    while (idx < str.size()) {
        min_num += '0';
        max_num += '1';
        idx++;
    }
    cout << max_num << '\n' << min_num;
}