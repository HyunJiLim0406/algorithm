#include <iostream>
#include <set>

using namespace std;

int main() {
    int N, M, cnt = 0;
    string input;
    set<string> str;

    cin >> N >> M;
    while (N--) { //set에 저장
        cin >> input;
        str.insert(input);
    }
    while (M--) {
        cin >> input;
        if (str.find(input) != str.end()) //존재하는 문자열인지 확인
            cnt++;
    }
    cout << cnt;
}