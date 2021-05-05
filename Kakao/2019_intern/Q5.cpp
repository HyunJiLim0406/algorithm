#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int result;

void binarySearch(vector<int> stones, int k, int left, int right) {
    if (left > right) //종료 조건
        return;
    int mid = (left + right) / 2; //mid명이 건널 수 있나?
    int cnt = 0;
    bool isPossible = true;
    for (int i = 0; i < stones.size(); i++) {
        if ((stones[i] - mid) < 0) { //0보다 작다면 cnt 증가
            cnt++;
            if (cnt == k) { //k와 같아지면 건널 수 없다는 것
                isPossible = false;
                break;
            }
        } else //0 이상이면 cnt를 0으로 초기화
            cnt = 0;
    }
    if (isPossible) { //mid명이 건널 수 있다면 오른쪽 탐색
        result = mid;
        binarySearch(stones, k, mid + 1, right);
    } else //mid명이 건널 수 없다면 왼쪽 탐색
        binarySearch(stones, k, left, mid - 1);
}

int solution(vector<int> stones, int k) {
    int init = 0;
    for (int i = 0; i < stones.size(); i++) //초기 right는 stone의 최댓값
        init = max(init, stones[i]);
    binarySearch(stones, k, 0, init);
    return result;
}

//parametric search
int main() {
    cout << solution({2, 4, 5, 3, 2, 1, 4, 2, 5, 1}, 3);
}