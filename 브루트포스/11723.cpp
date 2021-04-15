#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int M, num;
    string input;
    int S = 0;

    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> input;
        if (input.compare("add") == 0) {
            cin >> num;
            S |= 1 << num; // or 연산
        } else if (input.compare("remove") == 0) {
            cin >> num;
            S &= ~(1 << num); // reverse and 연산
        } else if (input.compare("check") == 0) {
            cin >> num;
            int tmp = S & (1 << num); // and 연산해서 0이 아니면 1 반환
            if (tmp)
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        } else if (input.compare("toggle") == 0) {
            cin >> num;
            S ^= 1 << num; // xor 연산
        } else if (input.compare("all") == 0)
            S = (1 << 21) - 1; //최댓값에서 1을 뺌
        else if (input.compare("empty") == 0)
            S = 0; //0으로 초기화
    }
}