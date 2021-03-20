#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

bool cmp(const string& s1, const string& s2) {
    if (s1.length() < s2.length()) //길이 비교
        return true;
    else if (s1.length() == s2.length()) //사전 비교
        return s1 < s2;
    else
        return false;
}

int main() {
    int N, i;
    string arr[20000];

    cin >> N;
    for (i = 0; i < N; i++)
        cin >> arr[i];
    sort(arr, arr + N, cmp);
    for (i = 0; i < N; i++) {
        if (arr[i].compare(arr[i + 1]) != 0) //중복 제거
            cout << arr[i] << '\n';
    }
}