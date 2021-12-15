#include <iostream>
#include <map>

using namespace std;

int main() {
    int n;
    string name;
    map<string, int> m; //동명이인이 있을 수 있으므로 맵

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> name;
        m[name]++;
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> name;
        m[name]--;
    }

    for (auto runner: m) {
        if (runner.second) { //여전히 남아있는 사람
            cout << runner.first;
            break;
        }
    }
}