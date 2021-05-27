#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N;
vector<int> s, t, tmp;

bool isSame() { //전구를 바꾸는데 성공했는지 확인
    for (int i = 0; i < tmp.size(); i++) {
        if (tmp[i] != t[i])
            return false;
    }
    return true;
}

void switchBulb(int idx) { //전구를 바꿔줌
    for (int i = idx - 1; i <= idx + 1; i++) {
        if ((i >= 0) && (i < N))
            tmp[i] ^= 1;
    }
}

int switchCnt() {
    int cnt = 0;
    for (int i = 1; i < N; i++) {
        if (tmp[i - 1] != t[i - 1]) { //이전 전구를 보며 스위치
            switchBulb(i);
            cnt++;
        }
    }
    return (isSame()) ? cnt : N + 1; //동일하게 바꾸는데 성공하면 cnt 리턴
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string input;

    cin >> N;
    int result = N + 1;
    s.assign(N, 0);
    t.assign(N, 0);
    for (int i = 0; i < 2; i++) {
        cin >> input;
        for (int j = 0; j < N; j++)
            (i == 0) ? s[j] = input[j] - '0' : t[j] = input[j] - '0';
    }

    //첫번째 전구 누르지 않음
    tmp = s;
    int cnt = switchCnt();
    result = min(result, cnt);

    //첫번째 전구 누름
    tmp = s;
    switchBulb(0);
    cnt = switchCnt() + 1;
    result = min(result, cnt);
    cout << ((result == N + 1) ? -1 : result);
}