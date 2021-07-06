#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
const int MAX_NUM = 1003002; //최댓값

vector<bool> is_prime(MAX_NUM, true);
vector<int> prime_palindrome;

void eratos() { //에라토스테네스의 체
    is_prime[0] = is_prime[1] = false;
    int line = sqrt(MAX_NUM) + 1;
    for (int i = 2; i <= line; i++) {
        if (is_prime[i]) {
            for (int j = i * 2; j < MAX_NUM; j += i)
                is_prime[j] = false;
        }
    }
}

bool isPalindrome(int num) {
    string str = to_string(num);
    for (int i = 0; i < str.size() / 2; i++) {
        if (str[i] != str[str.size() - i - 1])
            return false;
    }
    return true;
}

void palindrome() {
    for (int i = 2; i < MAX_NUM; i++) { //모든 소수에 대해 팰린드롬인지 확인
        if (is_prime[i] && isPalindrome(i))
            prime_palindrome.push_back(i);
    }
}

int main() {
    int N;

    cin >> N;
    eratos();
    palindrome();
    cout << *lower_bound(prime_palindrome.begin(), prime_palindrome.end(), N);
}