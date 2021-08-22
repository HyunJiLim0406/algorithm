#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> crane, box;

bool promising(int num) {
    vector<int> cnt(N, num); //각 크레인별 사용횟수
    for (int i = 0; i < M; i++) {
        int idx = lower_bound(crane.begin(), crane.end(), box[i]) - crane.begin(); //최적의 위치
        while (idx < N && !cnt[idx]) //사용할 수 있는 크레인 찾기
            idx++;
        if (idx == N) //사용할 수 있는 크레인 없음
            return false;
        cnt[idx]--; //사용
    }
    return true;
}

int lowerSearch(int left, int right) {
    while (left <= right) {
        int mid = (left + right) / 2; //이 시간안에 가능한가?
        if (promising(mid))
            right = mid - 1;
        else
            left = mid + 1;
    }
    return left;
}

int main() {
    cin >> N;
    crane.assign(N, 0);
    for (int i = 0; i < N; i++)
        cin >> crane[i];
    sort(crane.begin(), crane.end()); //정렬

    cin >> M;
    box.assign(M, 0);
    for (int i = 0; i < M; i++) {
        cin >> box[i];
        if (box[i] > crane[N - 1]) { //무게 제한이 가장 큰 크레인보다 상자가 무거움
            cout << -1;
            return 0;
        }
    }
    cout << lowerSearch(0, M);
}