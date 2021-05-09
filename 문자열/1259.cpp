#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    while (true) {
        bool isP = true;
        cin >> input;
        if (!input.compare("0"))
            break;
        for (int i = 0; i < input.size() / 2; i++) {
            if (input[i] != input[input.size() - i - 1]) {
                isP = false;
                cout << "no\n";
                break;
            }
        }
        if (isP)
            cout << "yes\n";
    }
}