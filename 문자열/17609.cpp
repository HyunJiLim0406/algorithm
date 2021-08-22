#include <iostream>

using namespace std;

bool isPalindrome(string str, int left, int right) {
    while (left <= right) {
        if (str[left] != str[right])
            return false;
        left++;
        right--;
    }
    return true;
}

int palindrome(string str) {
    int left = 0, right = str.size() - 1;
    while (left <= right) {
        if (str[left] == str[right]) {
            left++;
            right--;
            continue;
        }
        if (isPalindrome(str, left + 1, right)) //왼쪽 문자 삭제하면 펠린드롬?
            return 1;
        if (isPalindrome(str, left, right - 1)) //오른쪽 문자 삭제하면 펠린드롬?
            return 1;
        return 2;
    }
    return 0;
}

int main() {
    int N;
    string str;

    cin >> N;
    while (N--) {
        cin >> str;
        cout << palindrome(str) << '\n';
    }
}