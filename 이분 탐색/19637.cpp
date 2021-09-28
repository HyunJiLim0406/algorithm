#include <iostream>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    map<int, string> mapping;

    int n, m, power;
    string name;

    cin >> n >> m;
    while (n--) {
        cin >> name >> power;
        if (mapping[power].empty()) //이미 입력이 있음
            mapping[power] = name;
    }
    while (m--) {
        cin >> power;
        cout << mapping.lower_bound(power)->second << '\n';
    }
}