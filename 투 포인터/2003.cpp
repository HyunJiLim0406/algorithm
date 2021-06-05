#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;

    cin >> N >> M;
    vector<int> arr(N + 1, 0); //뒤에 값 하나 추가
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    int left = 0, right = 0, num = arr[0], cnt = 0;
    while (left < N && right < N) {
        if (num >= M) { //M 이상이면 left 포인터 이동
            if (num == M) //M과 같을 때
                cnt++;
            num -= arr[left++];
        } else  //M 미만이면 right 포인터 이동
            num += arr[++right];
    }
    cout << cnt;
}