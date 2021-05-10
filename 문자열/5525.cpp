#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, result = 0;
    string S;

    cin >> N >> M >> S;
    int idx = 0;
    while (idx < M) {
        if (S[idx] == 'I') { //'I' 라면
            int cnt = 0; //P의 길이
            while (((idx + 2) < M) && (S[idx + 1] == 'O') && (S[idx + 2] == 'I')) { //IOI
                cnt++;
                if (cnt == N) { //Pn의 길이와 같아지면
                    result++;
                    cnt--; //ex) N=2, IOIOIOI
                }
                idx += 2;
            }
        }
        idx++;
    }
    cout << result;
}