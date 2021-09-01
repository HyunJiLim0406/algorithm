#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
typedef long double ld;

vector<ld> arr;

ld deviation(int left, int right, ld avg) {
    ld variance = 0.0;
    for (int i = left; i <= right; i++) //분산
        variance += pow(arr[i] - avg, 2);
    return sqrt(variance / (right - left + 1));
}

int main() {
    int N, K;
    ld result = 1e9;

    cin >> N >> K;
    vector<ld> sum(N + 1);
    arr.assign(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        sum[i] = arr[i] + sum[i - 1]; //누적합
    }

    for (int i = K; i <= N; i++) { //i개의 인형에 대해
        int left = 1, right = i;
        while (right <= N) {
            ld avg = (sum[right] - sum[left - 1]) / (right - left + 1); //평균
            result = min(result, deviation(left, right, avg)); //표준편차 갱신
            left++;
            right++;
        }
    }

    cout << fixed;
    cout.precision(10);
    cout << result;
}