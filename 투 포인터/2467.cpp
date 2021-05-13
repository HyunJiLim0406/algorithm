#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector<int> liquid;

pair<int, int> twoPointer(int left, int right) {
    int min_diff = 2 * 1e9 + 1;
    pair<int, int> result;
    while (left < right) { //둘의 위치가 역전되면 break
        int sum = liquid[left] + liquid[right];
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
    pair<int, int> result = twoPointer(0, N - 1);
    cout << result.first << ' ' << result.second;
}