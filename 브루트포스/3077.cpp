#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int N, correct = 0;
    string input;
    map<string, int> m;

    cin >> N;
    vector<string> answer(N);
    for (int i = 0; i < N; i++) { //정답 순서
        cin >> input;
        m[input] = i;
    }
    for (int i = 0; i < N; i++)
        cin >> answer[i];
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (m[answer[i]] < m[answer[j]]) //순서가 맞다면
                correct++;
        }
    }
    cout << correct << '/' << N * (N - 1) / 2;
}