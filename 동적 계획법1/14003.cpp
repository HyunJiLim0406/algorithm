#include <iostream>
#include <stack>

using namespace std;

int arr[1000001][2], dp[1000001]; //arr[i][1] = k, i번째 원소의 최장 길이 수열의 길이는 k
stack<int> result;

int lowerBound(int left, int right, int key) { //lower bound를 찾는 함수
    while (left <= right) {
        int mid = (left + right) / 2;
        if (dp[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return right + 1;
}

int lis(int n) {
    int length = 0;

    for (int i = 1; i <= n; i++) {
        int pos = lowerBound(1, length, arr[i][0]); //arr[i][0]이 들어가야 할 위치 반환
        dp[pos] = arr[i][0];
        arr[i][1] = pos;
        if (pos > length) //증가 수열의 길이가 증가하는 상황
            length++;
    }
    int tmp = length; //길이 임시 저장
    for (int i = n; i >= 1; i--) {
        if (arr[i][1] == tmp) { //인덱스 확인하며 스택에 투입
            result.push(arr[i][0]);
            tmp--;
        }
    }
    return length;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> arr[i][0];
    cout << lis(N) << '\n'; //길이 출력
    while (!result.empty()) { //수열 출력
        cout << result.top() << ' ';
        result.pop();
    }
}