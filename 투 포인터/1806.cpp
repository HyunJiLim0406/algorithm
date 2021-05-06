#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;

int minLen(int S) {
    int result = arr.size() + 1;
    int left = 0, right = 0; //왼쪽에서 시작

    int sum = arr[left];
    while ((left < arr.size()) && (right < arr.size())) { //범위 내에 있을 떄
        if (sum >= S) { //S 이상이면 result 갱신하고 left 증가
            result = min(result, right - left + 1);
            sum -= arr[left];
            left++;
        } else { //S 미만이면 right 증가
            if (right < arr.size())
                sum += arr[right + 1];
            right++;
        }
    }
    if (result == arr.size() + 1) //result 갱신된 적 없으면 0 리턴
        return 0;
    else //result 갱신된 적 있으면 result 리턴
        return result;
}

int main() {
    int N, S;

    cin >> N >> S;
    arr.assign(N, 0);
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    cout << minLen(S);
}