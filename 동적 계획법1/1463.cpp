#include <iostream>
#include <algorithm>
using namespace std;

int min_arr[1000001] = { 0, };

int findMin(int a, int b, int c) { //인자 3개 min 함수
    if (a < b) {
        if (a < c)
            return a;
        else
            return c;
    }
    else {
        if (b < c)
            return b;
        else
            return c;
    }
}

int making_one(int num) {
    for (int i = 1; i <= num; i++) {
        if (i <= 3) //1일 때는 0, 2 or 3일 때는 1이 들어가도록
            min_arr[i] = i / 2;
        else {
            if (i % 2 == 0 && i % 3 == 0) //2와 3으로 나누어 떨어질 때 3개 비교
                min_arr[i] = findMin(min_arr[i / 2], min_arr[i / 3], min_arr[i - 1]) + 1;
            else if (i % 2 == 0) //2로만 나누어 떨어질 때 2개 비교
                min_arr[i] = min(min_arr[i / 2], min_arr[i - 1]) + 1;
            else if (i % 3 == 0) //3로만 나누어 떨어질 때 2개 비교
                min_arr[i] = min(min_arr[i / 3], min_arr[i - 1]) + 1;
            else //나누어 떨어지지 않을 때
                min_arr[i] = min_arr[i - 1] + 1;
        }
    }
    return min_arr[num];
}

int main() {
    int N;

    cin >> N;
    cout << making_one(N);
}