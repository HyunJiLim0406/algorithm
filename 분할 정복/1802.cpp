#include <iostream>
#include <algorithm>

using namespace std;

bool promising(string str1, string str2) { //하나라도 같다면 false
    for (int i = 0; i < str1.size(); i++) {
        if (str1[i] == str2[i])
            return false;
    }
    return true;
}

bool divide(string str) {
    if (str.size() == 1) //길이가 1이면 더이상 탐색 X
        return true;

    int mid = str.size() / 2;
    string left = str.substr(0, mid); //왼쪽 문자열
    string right = str.substr(mid + 1); //오른쪽 문자열
    reverse(right.begin(), right.end()); //뒤집기
    if (!promising(left, right)) //겹쳐지나?
        return false;
    return divide(left); //왼쪽에 대해서만 재귀호출
}

int main() {
    int t;
    string str;

    cin >> t;
    while (t--) {
        cin >> str;
        bool ans = divide(str);
        cout << ((ans) ? "YES" : "NO") << '\n';
    }
}