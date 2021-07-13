#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

vector<ll> dp;
vector<bool> is_checked;

void fillDp(int N) { //팩토리얼
    dp.assign(N + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= N; i++)
        dp[i] = dp[i - 1] * i;
}

vector<int> findArr(int N, ll k) { //배열 찾기
    is_checked.assign(N + 1, false);
    vector<int> result;
    for (int i = 0; i < N; i++) {
        for (int j = 1; j <= N; j++) {
            if (is_checked[j]) //이미 사용한 숫자
                continue;
            if (dp[N - i - 1] < k) //k=15라면 1___에서 dp[N-i-1]=6이라 충분하지 않음
                k -= dp[N - i - 1];
            else { //적당한 숫자를 찾음
                result.push_back(j);
                is_checked[j] = true;
                break;
            }
        }
    }
    return result;
}

ll findSeq(int N, vector<int> arr) {
    is_checked.assign(N + 1, false);
    ll result = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 1; j < arr[i]; j++) { //arr[i]보다 작은 숫자들
            if (!is_checked[j]) //사용한 숫자가 아니라면
                result += dp[N - i - 1]; //그 숫자들로 만들어졌을 배열의 경우의 수
        }
        is_checked[arr[i]] = true; //사용 체크
    }
    return result;
}

int main() {
    ll k;
    int N, cmd;

    cin >> N >> cmd;
    fillDp(N);
    if (cmd == 1) {
        cin >> k;
        vector<int> result = findArr(N, k);
        for (auto num:result)
            cout << num << ' ';
    } else if (cmd == 2) {
        vector<int> arr(N);
        for (int i = 0; i < N; i++)
            cin >> arr[i];
        cout << findSeq(N, arr);
    }
}