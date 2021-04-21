#include <iostream>
#include <string>

using namespace std;

int main() {
    while (true) {
        string str;
        int cnt[4] = {0};
        getline(cin, str);
        if (str.size() == 0)
            break;

        for (int i = 0; i < str.size(); i++) {
            if ((str[i] >= 'a') && (str[i] <= 'z'))
                cnt[0]++;
            else if ((str[i] >= 'A') && (str[i] <= 'Z'))
                cnt[1]++;
            else if ((str[i] >= '0') && (str[i] <= '9'))
                cnt[2]++;
            else
                cnt[3]++;
        }
        for (int i = 0; i < 4; i++)
            cout << cnt[i] << ' ';
    }
}