#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;

    getline(cin, str);
    for (int i = 0; i < str.size(); i++) {
        if ((str[i] >= 'a') && (str[i] <= 'z')) {
            if ((str[i] + 13) <= 'z')
                cout << char(str[i] + 13);
            else
                cout << char(str[i] - 13);
        } else if ((str[i] >= 'A') && (str[i] <= 'Z')) {
            if ((str[i] + 13) <= 'Z')
                cout << char(str[i] + 13);
            else
                cout << char(str[i] - 13);
        } else
            cout << str[i];
    }
}