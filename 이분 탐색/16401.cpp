#include <iostream>
#include <vector>

using namespace std;

vector<int> cookie;

int cntPeople(int len) {
    int cnt = 0;
    for (int i = 0; i < cookie.size(); i++)
        cnt += cookie[i] / len;
    return cnt;
}

int upperSearch(int left, int right, int target) {
    int ans = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        int share = cntPeople(mid); //이 길이로 나눠줄 수 있는 인원
        if (share >= target) { //길이 늘리기
            ans = mid;
            left = mid + 1;
        }
        if (share < target) //길이 줄이기
            right = mid - 1;
    }
    return ans;
}

int main() {
    int m, n, max_cookie = 0;

    cin >> m >> n;
    cookie.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> cookie[i];
        max_cookie = max(max_cookie, cookie[i]); //제일 긴 쿠기
    }
    cout << upperSearch(1, max_cookie, m);
}