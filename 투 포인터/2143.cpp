#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void accumulateArr(vector<int> &arr) { //누적합
    for (int i = 1; i < arr.size(); i++)
        arr[i] += arr[i - 1];
}

vector<int> subArr(vector<int> arr) { //부 배열 (B에 대해서만 구하기)
    vector<int> result = arr;
    for (int i = 1; i < arr.size(); i++) {
        for (int j = i; j < arr.size(); j++)
            result.push_back(arr[j] - arr[i - 1]);
    }
    return result;
}

int main() {
    long long cnt = 0; //int 범위 넘어갈 수도
    int T, n, m;

    cin >> T >> n;
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> A[i];
    cin >> m;
    vector<int> B(m);
    for (int i = 0; i < m; i++)
        cin >> B[i];
    accumulateArr(A); //A의 누적합
    accumulateArr(B); //B의 누적합
    vector<int> sub_B = subArr(B); //B의 부 배열
    sort(sub_B.begin(), sub_B.end()); //정렬
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            int num = T - (A[j] - A[i - 1]); //찾아야 할 수
            cnt += upper_bound(sub_B.begin(), sub_B.end(), num) - lower_bound(sub_B.begin(), sub_B.end(), num);
        }
    }
    cout << cnt;
}