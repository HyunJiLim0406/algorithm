#include <iostream>
#include <stack>

using namespace std;

int arr[1001][2], dp[1001]; //arr[i][1] = k, i번째 원소의 최장 길이 수열의 길이는 k
stack<int> result;

int lis(int n) {
    int length = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = length; j >= 0; j--) {
            if (arr[i][0] > dp[j]) {
                dp[j + 1] = arr[i][0];
                arr[i][1] = j + 1; //i번째 원소의 길이 저장
                if (j == length) //최장 길이 증가
                    length++;
                break;
            }
        }
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