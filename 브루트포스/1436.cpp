#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() { //이게 된다구..?
    int N, count = 0;

    cin >> N;
    for (int i = 666;; i++) { //666부터 시작해서
        string str = to_string(i); //숫자 문자로 바꾼다음에
        if (str.find("666") != string::npos) //666패턴 체크함
            count++;
        if (N == count) { //계속 체크하다 원하는 만큼 찾으면 출력했는데
            cout << i << '\n';
            break;
        }
    } //이게 시간 초과가 안난다구..?
}