#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

vector<int> arr;

pair<int, int> findPair() {
    pair<int, int> result;
    int min_diff = 2 * 1e9 + 1;
    int left = 0;
    int right = arr.size() - 1;

    while (left < right) { //둘의 위치가 역전되면 break
        int sum = arr[left] + arr[right];
        if (sum == 0) { //0이면 바로 리턴
            result = make_pair(arr[left], arr[right]);
            return result;
        } else { //0이 아닐 때
            if (abs(sum) < min_diff) { //최소 차이 갱신 가능한지 확인
                result = make_pair(arr[left], arr[right]);
                min_diff = abs(sum);
            }
            if (sum > 0) //0보다 크면 right 감소
                right--;
            else //0보다 작으면 left 증가
                left++;
        }
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    arr.assign(N, 0);
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    pair<int, int> p = findPair();
    cout << p.first << ' ' << p.second;
}