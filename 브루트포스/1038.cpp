#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

vector<ll> result;

void backtracking(ll num, int len) { //가능한 모든 감소하는 수
    if (len > 10) //9876543210, 즉 최대 길이는 10
        return;
    result.push_back(num);
    for (int i = 0; i < 10; i++) {
        if (num % 10 > i) //맨 뒤에 넣기
            backtracking(num * 10 + i, len + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    for (int i = 0; i < 10; i++) //0~9로 시작하는 감소하는 수
        backtracking(i, 1);
    sort(result.begin(), result.end()); //정렬
    cout << ((N >= result.size()) ? -1 : result[N]);
}