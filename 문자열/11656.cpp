#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string str;
    string arr[1001];

    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        for (int j = i; j < str.size(); j++)
            arr[i] += str[j];
    }
    sort(arr, arr + str.size()); //정렬
    for (int i = 0; i < str.size(); i++)
        cout << arr[i] << '\n';
}