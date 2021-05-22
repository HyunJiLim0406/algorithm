#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

map<char, int> alphabet;
vector<string> str_arr;

bool cmp(const pair<char, int> &p1, const pair<char, int> &p2) {
    return p1.second < p2.second;
}

int toInteger(string x) {
    int result = 0, mul = 1;
    for (int i = x.size() - 1; i >= 0; i--) {
        result += (mul * alphabet[x[i]]);
        mul *= 10;
    }
    return result;
}

int main() { //그리디
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string input;

    cin >> N;
    str_arr.assign(N, "");
    for (int i = 0; i < N; i++) {
        cin >> str_arr[i];
        int mul = 1;
        for (int j = str_arr[i].size() - 1; j >= 0; j--) { //자릿수에 따른 알파벳별 가중치 부여
            alphabet[str_arr[i][j]] += mul;
            mul *= 10;
        }
    }
    vector<pair<char, int>> sort_alphabet(alphabet.begin(), alphabet.end()); //map 복사한 vector
    sort(sort_alphabet.begin(), sort_alphabet.end(), cmp); //가중치 순으로 오름차순 정렬

    for (int i = 0; i < sort_alphabet.size(); i++) //알파벳별 번호 부여
        alphabet[sort_alphabet[i].first] = i + (10 - sort_alphabet.size());
    int result = 0;
    for (int i = 0; i < N; i++) //계산
       result += toInteger(str_arr[i]);
    cout << result;
}