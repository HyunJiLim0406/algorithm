#include <iostream>
#include <string>

using namespace std;

/*
N=10일 때
AAAAAAAAAB => 9
AAAAAAAABB => 16
AAAAAAABBB => 21
AAAAAABBBB => 24
AAAAABBBBB => 25(최대)
*/
int main() {
    int N, K;
    string str = "";

    cin >> N >> K;
    if (K > ((N / 2) * (N - (N / 2)))) { //만들 수 없음
        cout << -1;
        return 0;
    }
    for (int i = 0; i < N; i++) //전부 A로 채움
        str += 'A';

    int idx = 1;
    while (K > (idx * (N - idx))) //B가 몇 개 필요한지 계산
        idx++;

    int b_idx; //마지막 B의 위치
    //K=17이라면 idx=3, 17/3=5이므로 맨 앞에 연속으로 들어가는 A의 개수는 5개, 그 뒤로 B를 3개 입력
    for (int i = (K / idx); i < (K / idx) + idx; i++) {
        str[i] = 'B';
        b_idx = i;
    }
    for (int i = 0; i < (K % idx); i++) { //나머지의 수만큼 B를 한칸씩 뒤로 옯겨줌
        swap(str[b_idx], str[b_idx+1]);
        b_idx--;
    }
    cout << str;
}