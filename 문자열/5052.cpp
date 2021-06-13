#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isPrefix(string a, string b) { //a가 b의 접두사가 되는지 확인
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i])
            return false;
    }
    return true;
}

bool isConsistent(vector<string> arr) {
    for (int i = 0; i < arr.size() - 1; i++) { //인접한 문자열만 비교
        if (isPrefix(arr[i], arr[i + 1]))
            return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n;

    cin >> t;
    while (t--) {
        cin >> n;
        vector<string> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        sort(arr.begin(), arr.end()); //사전순 정렬
        if (isConsistent(arr))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}