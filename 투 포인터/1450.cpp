#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

vector<ll> arr;

vector<ll> splitArr(int left, int len) { //비트 마스킹으로 각 배열에 대한 연산
    vector<ll> result;
    for (int i = 0; i < (1 << len); i++) {
        ll sum = 0;
        for (int j = 0; j < len; j++) {
            if (((1 << j) & i) != 0)
                sum += arr[left + j];
        }
        result.push_back(sum);
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, C, result = 0;

    cin >> N >> C;
    arr.assign(N, 0);
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    vector<ll> front_arr = splitArr(0, N / 2); //앞의 절반
    vector<ll> back_arr; //뒤의 절반
    if (N % 2 == 0) //배열의 크기가 짝수일 때
        back_arr = splitArr(N / 2, N / 2);
    else //배열의 크기가 홀수일 때
        back_arr = splitArr(N / 2, N / 2 + 1);
    sort(back_arr.begin(), back_arr.end()); //정렬
    for (int i = 0; i < front_arr.size(); i++) //back_arr에서 C-front_arr[i]에 대한 upper_bound 찾기
        result += upper_bound(back_arr.begin(), back_arr.end(), C - front_arr[i]) - back_arr.begin();
    cout << result;
}