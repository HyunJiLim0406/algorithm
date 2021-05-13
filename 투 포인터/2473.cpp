#include <iostream>
#include <vector>
#include <utility>
#include <tuple>
#include <algorithm>

using namespace std;
typedef long long ll;
const long long INF = 3 * 1e9 + 1;

vector<ll> liquid;
ll min_diff = INF;

pair<ll, ll> twoPointer(ll fixed, int left, int right) {
    pair<ll, ll> result;
    result = make_pair(INF, INF); //갱신이 안될 수도 있으므로 초기값 넣기
    while (left < right) { //둘의 위치가 역전되면 break
        ll sum = fixed + liquid[left] + liquid[right];
        if (sum == 0) //0이면 바로 리턴
            return make_pair(liquid[left], liquid[right]);
        if (abs(sum) < min_diff) { //최소 차이 갱신 가능한지 확인
            min_diff = abs(sum);
            result = make_pair(liquid[left], liquid[right]);
        }
        if (sum > 0) //0보다 크면 right 감소
            right--;
        else //0보다 작으면 left 증가
            left++;
    }
    return result;
}

int main() {
    int N;

    cin >> N;
    liquid.assign(N, 0);
    for (int i = 0; i < N; i++)
        cin >> liquid[i];
    sort(liquid.begin(), liquid.end()); //정렬
    tuple<ll, ll, ll> result;
    for (int i = 0; i < N - 2; i++) { //liquid[i]는 고정 용액
        pair<ll, ll> p = twoPointer(liquid[i], i + 1, N - 1);
        if ((p.first != INF) && (p.second != INF)) //최소 차이가 갱신됐으면 result 갱신
            result = make_tuple(liquid[i], p.first, p.second);
    }
    cout << get<0>(result) << ' ' << get<1>(result) << ' ' << get<2>(result);
}