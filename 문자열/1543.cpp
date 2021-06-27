#include <iostream>
#include <string>

using namespace std;

int main() {
    string source, target;

    getline(cin, source);
    getline(cin, target);
    int cnt = 0;
    while (source.find(target) != string::npos) { //찾지 못할 때까지 반복
        cnt++;
        source = source.substr(source.find(target) + target.size()); //문자열 자르기
    }
    cout << cnt;
}