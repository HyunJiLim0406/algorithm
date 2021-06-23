#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int calc(string s) {
    int result = 0;
    for (int i = 0; i < s.size(); i++) {
        if (isdigit(s[i])) //숫자라면
            result += s[i] - '0';
    }
    return result;
}

bool cmp(const string &s1, const string &s2) {
    if (s1.size() != s2.size()) //길이 비교
        return s1.size() < s2.size();
    if (calc(s1) != calc(s2)) //계산 비교
        return calc(s1) < calc(s2);
    return s1 < s2; //사전순
}

int main() {
    int N;

    cin >> N;
    vector<string> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end(), cmp); //정렬
    for (int i = 0; i < N; i++)
        cout << arr[i] << '\n';
}