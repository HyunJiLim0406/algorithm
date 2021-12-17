#include <iostream>
#include <set>
#include <string>

using namespace std;

int stringToInt(string str) {
    int h = stoi(str.substr(0, 2));
    int m = stoi(str.substr(3, 2));
    return h * 60 + m;
}

int main() {
    string input;
    set<string> list;

    getline(cin, input);
    int start = stringToInt(input.substr(0, 5));
    int end = stringToInt(input.substr(6, 5));
    int quit = stringToInt(input.substr(12, 5));
    int ans = 0;

    while (getline(cin, input)) {
        int t = stringToInt(input.substr(0, 5));
        string nick = input.substr(6);
        if (t <= start) //입장
            list.insert(nick);
        if (end <= t && t <= quit && list.find(nick) != list.end()) { //퇴장
            ans++;
            list.erase(nick);
        }
    }
    cout << ans;
}