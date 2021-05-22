#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

map<char, int> alphabet;
vector<string> str_arr;
vector<int> arr;

int toInteger(string x) {
    int result = 0, mul = 1;
    for (int i = x.size() - 1; i >= 0; i--) {
        int idx = alphabet[x[i]] - 1;
        result += (mul * arr[idx]);
        mul *= 10;
    }
    return result;
}

int main() { //브루트 포스
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, init = 1;
    string input;

    cin >> N;
    str_arr.assign(N, "");
    for (int i = 0; i < N; i++) {
        cin >> str_arr[i];
        for (int j = 0; j < str_arr[i].size(); j++) {
            if (alphabet[str_arr[i][j]] == 0) //각 알파벳에 인덱스 부여
                alphabet[str_arr[i][j]] = init++;
        }
    }
    for (int i = 9; i > (10 - init); i--) //내림차순 순열
        arr.push_back(i);
    int result = 0;
    do { //모든 순열 조합 고려
        int sum = 0;
        for (int i = 0; i < N; i++)
            sum += toInteger(str_arr[i]);
        result = max(result, sum); //최댓값 갱신
    } while (prev_permutation(arr.begin(), arr.end()));
    cout << result;
}