#include <iostream>
#include <algorithm>
using namespace std;

int stair[301] = { 0, };
int stair_max[301] = { 0, }; //배열 하나에 갱신하지 말고 최대값만 저장할 배열을 생각했어야 함

int jump_stair(int num) { //나중에 다시 풀어보기. 어려웠음
    for (int i = 0; i <= num; i++) {
        if (i < 3) {
            for (int j = 0; j <= i; j++)
                stair_max[i] += stair[j];
        }
        else { //점화식을 먼저 짜보자. 배열 하나로 할 생각 X
            stair_max[i] = stair[i] + max(stair[i - 1] + stair_max[i - 3], stair_max[i - 2]);
        }
    }
    return stair_max[num];
}

int main() {
    int N;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> stair[i];
    cout << jump_stair(N);
}