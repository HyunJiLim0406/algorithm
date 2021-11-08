#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main() {
    int n;
    string pattern, input;

    cin >> n >> pattern;
    string np;
    for (int i = 0; i < pattern.size(); i++) { //정규 표현식으로 만들기
        if (pattern[i] == '*')
            np += "[a-z]";
        np += pattern[i];
    }

    regex re(np);
    while (n--) {
        cin >> input;
        if (regex_match(input, re))
            cout << "DA\n";
        else
            cout << "NE\n";
    }
}