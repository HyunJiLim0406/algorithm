#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> pi;

void generatePi(string str) { //일치하는 가장 긴 접두사와 접미사
    pi.assign(str.size(), 0);
    int p_idx = 0;
    for (int i = 1; i < str.size(); i++) {
        while (p_idx > 0 && str[i] != str[p_idx])
            p_idx = pi[p_idx - 1];
        if (str[i] == str[p_idx])
            pi[i] = ++p_idx;
    }
}

int main() {
    int result = 0;
    string str;

    cin >> str;
    while (str.size() > 1) {
        generatePi(str);
        str = str.substr(1); //접두사 자르기
        for (int i = 0; i < pi.size(); i++) //최대길이 갱신
            result = max(result, pi[i]);
    }
    cout << result;
}