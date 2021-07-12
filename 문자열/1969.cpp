#include <iostream>
#include <vector>
#include <string>

using namespace std;

pair<char, int> findChar(vector<vector<int>> &table, int idx) {
    char ch;
    int max_cnt = 0;
    for (int i = 0; i < 26; i++) {
        if (table[i][idx] > max_cnt) { //제일 많이 등장한 알파벳 갱신
            max_cnt = table[i][idx];
            ch = i + 'A';
        }
    }
    return make_pair(ch, max_cnt);
}

int main() {
    int N, M, cnt = 0;
    string input, result;

    cin >> N >> M;
    vector<vector<int>> table(26, vector<int>(M));
    for (int i = 0; i < N; i++) {
        cin >> input;
        for (int j = 0; j < M; j++) //각 알파벳의 등장 횟수 증가
            table[input[j] - 'A'][j]++;
    }
    for (int i = 0; i < M; i++) {
        pair<char, int> ch = findChar(table, i);
        result += ch.first; //문자열 붙이기
        cnt += ch.second; //해당 문자의 등장 횟수(해밍 일치)
    }
    cout << result << '\n' << N * M - cnt;
}