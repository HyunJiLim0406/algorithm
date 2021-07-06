#include <iostream>
using namespace std;

struct bi_arr { //l은 왼쪽부터 오름차순, r은 오른쪽부터 오름차순
    int value, l_point, r_point;
};
bi_arr* arr = new bi_arr[1001];
int dp[1001] = { 0, };
int point = 1;

void cal(int index, int* dp, int flag) { //11053과 같음
    for (int i = point; i >= 0; i--) {
        if (arr[index].value > dp[i]) {
            dp[i + 1] = arr[index].value;
            if (flag == 0)
                arr[index].l_point = i + 1;
            else
                arr[index].r_point = i + 1;
            if (i == point)
                point++;
            return;
        }
    }
}

int bitonic(int num) {
    dp[1] = arr[1].value;
    arr[1].l_point = 1;
    for (int i = 2; i <= num; i++) { //왼쪽부터 순회
        cal(i, dp, 0);
    }
    point = 1; //dp 포인터 초기화

    dp[1] = arr[num].value;
    arr[num].r_point = 1;
    for (int i = num - 1; i >= 1; i--) { //오른쪽부터 순회
        cal(i, dp, 1);
    }

    int max = 0;
    for (int i = 1; i <= num; i++) { //max값 찾기
        if (arr[i].l_point + arr[i].r_point > max)
            max = arr[i].l_point + arr[i].r_point;
    }
    return max - 1; //1개 중복 계산되니까 1빼기
}

int main() {
    int N;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> arr[i].value;
    cout << bitonic(N);
}