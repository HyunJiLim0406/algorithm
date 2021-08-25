#include <iostream>
#include <vector>
#include <map>

using namespace std;
typedef long long ll;

int main() {
    int N, K;
    ll result = 0;
    map<int, ll> m;

    cin >> N >> K;
    vector<int> arr(N + 1, 0);
    for (int i = 1; i <= N; i++) { //누적 합
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }
    for (int i = 0; i <= N; i++) { //S[t] = S[i]-k인 t를 찾아서 더하고 map 갱신
        result += m[arr[i] - K];
        m[arr[i]]++;
    }
    cout << result;
}