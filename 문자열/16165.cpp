#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main() {
    int n, m, num;
    string input, group, member;

    map<string, set<string>> m1; //멤버 사전 순으로 정렬
    map<string, string> m2; //멤버의 그룹
    cin >> n >> m;
    while (n--) {
        cin >> group >> num;
        while (num--) {
            cin >> member;
            m1[group].insert(member);
            m2[member] = group;
        }
    }

    while (m--) {
        cin >> input >> num;
        if (num == 0) { //멤버
            for (auto mem: m1[input])
                cout << mem << '\n';
        }
        if (num == 1) //그룹
            cout << m2[input] << '\n';
    }
}