#include <iostream>
#include <set>

using namespace std;

string revStr(int start, int end, string input) { //범위 내의 문자열을 뒤집어서 반환
    string tmp;
    for (int i = end; i >= start; i--)
        tmp += input[i];
    return tmp;
}

int main() {
    string input;
    set<string> ans;

    cin >> input;
    for (int i = 0; i < input.size() - 2; i++) {
        for (int j = i + 1; j < input.size() - 1; j++)
            ans.insert(revStr(0, i, input) + revStr(i + 1, j, input) + revStr(j + 1, input.size() - 1, input));
    }
    cout << *ans.begin();
}