#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

vector<ll> arr;

vector<ll> calc(int left, int size) { //각 그룹의 부분합 벡터 만들기
    vector<ll> result;
    for (int i = 0; i < (1 << size); i++) {
        ll tmp = 0;
        for (int j = 0; j < size; j++) {
            if ((i & (1 << j)) != 0) {
                tmp += arr[left + j];
            }
        }
        result.push_back(tmp);
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll N, S;

    cin >> N >> S;
    arr.assign(N, 0);
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    vector<ll> group1 = calc(0, N / 2);
    vector<ll> group2;
    if (N % 2 == 0) //배열의 원소가 짝수
        group2 = calc(N / 2, N / 2);
    else //배열의 원소가 홀수
        group2 = calc(N / 2, N / 2 + 1);
    sort(group2.begin(), group2.end()); //정렬

    ll cnt = 0;
    for (int i = 0; i < group1.size(); i++) {
        ll target = S - group1[i];
        cnt += (upper_bound(group2.begin(), group2.end(), target) - lower_bound(group2.begin(), group2.end(), target)); //group2에서 target의 수 찾기
    }
    cout << ((S == 0) ? cnt - 1 : cnt); //S가 0이면 cnt-1 출력 아니면 cnt 출력
}