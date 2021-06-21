#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    int n;
    string name, status;
    map<string, bool, greater<>> stay; //사전의 역순으로 정렬

    cin >> n;
    while (n--) {
        cin >> name >> status;
        if (status == "enter") //출근
            stay[name] = true;
        else if (status == "leave") //퇴근
            stay[name] = false;
    }
    for (const auto& info:stay) {
        if (info.second) //출근 상태라면 출력
            cout << info.first << '\n';
    }
}