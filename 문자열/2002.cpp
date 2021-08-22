#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int N, result = 0;
    string str;
    map<string, int> m;

    cin >> N;
    vector<int> seq(N);
    for (int i = 0; i < N; i++) { //들어갈 때의 차들의 순서
        cin >> str;
        m[str] = i;
    }
    for (int i = 0; i < N; i++) { //나올 때의 차들의 순서
        cin >> str;
        seq[i] = m[str];
    }
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (seq[i] > seq[j]) { //한대라도 추월했다면
                result++;
                break;
            }
        }
    }
    cout << result;
}