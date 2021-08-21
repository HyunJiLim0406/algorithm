#include <iostream>
#include <vector>

using namespace std;

vector<int> alphaMap(string str) { //알파벳별 등장횟수 저장
    vector<int> result(26, 0);
    for (int i = 0; i < str.size(); i++)
        result[str[i] - 'A']++;
    return result;
}

int main() {
    int N, result = 0;
    string source, target;

    cin >> N >> source;
    vector<int> source_alpha = alphaMap(source);
    N--;
    while (N--) {
        cin >> target;

        int cnt = 0;
        vector<int> target_alpha = alphaMap(target);
        for (int i = 0; i < 26; i++) //차이
            cnt += abs(source_alpha[i] - target_alpha[i]);
        if (cnt <= 1 || (cnt == 2 && source.size() == target.size())) //차이가 1보다 작거나, 2이면서 두 문자열의 길이가 같을 때
            result++;
    }
    cout << result;
}