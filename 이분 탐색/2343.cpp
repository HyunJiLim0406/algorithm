#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> lessons;

bool isPromise(int len, int M) {
    int cnt = 1, local_len = 0;
    for (int i = 0; i < lessons.size(); i++) {
        if (local_len + lessons[i] > len) { //더이상 이 블루레이에 넣을 수 없으면 초기화
            local_len = 0;
            cnt++;
            i--;
        } else //누적
            local_len += lessons[i];
        if (cnt > M) //블루레이가 M개보다 많으면 불가능
            return false;
    }
    return true;
}

int lowerSearch(int left, int right, int M) { //lower-bound
    while (left <= right) {
        int mid = (left + right) / 2;
        if (!isPromise(mid, M))
            left = mid + 1;
        else
            right = mid - 1;
    }
    return right + 1;
}

int main() {
    int N, M, left = 0, right = 0;

    cin >> N >> M;
    lessons.assign(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> lessons[i];
        left = max(left, lessons[i]); //각 레슨 중 가장 긴 레슨
        right += lessons[i]; //모든 레슨의 총합
    }
    cout << lowerSearch(left, right, M);
}