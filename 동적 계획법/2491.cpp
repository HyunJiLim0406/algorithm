#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;

int fillDp(int N) {
    int result = 1;
    vector<int> increase(N), decrease(N);
    increase[0] = decrease[0] = 1; //초기화
    for (int i = 1; i < N; i++) {
        increase[i] = increase[i - 1] + 1; //증가한다고 가정
        decrease[i] = decrease[i - 1] + 1; //감소한다고 가정
        if (arr[i] > arr[i - 1]) //증가 수열이면 감소 초기화
            decrease[i] = 1;
        else if (arr[i] < arr[i - 1]) //감소 수열이면 증가 초기화
            increase[i] = 1;
        result = max(result, max(increase[i], decrease[i])); //최댓값 갱신
    }
    return result;
}

int main() {
    int N;

    cin >> N;
    arr.assign(N, 0);
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    cout << fillDp(N);
}