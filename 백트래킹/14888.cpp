#include <iostream>
using namespace std;

int min_num = 1000000000;
int max_num = -1000000000;
int arr[11];
int op[4];
int N;

int cal(int a, int b, int op) { //계산
    int result = 0;
    switch (op) {
        case 0:
            result = a + b;
            break;
        case 1:
            result = a - b;
            break;
        case 2:
            result = a * b;
            break;
        case 3:
            result = a / b;
            break;
    }
    return result;
}

void put_operator(int result, int index) {
    if (index == N - 1) { //노드 맨 아래까지 탐색하면 결과 비교
        if (result > max_num)
            max_num = result;
        if (result < min_num)
            min_num = result;
    }
    for (int i = 0; i < 4; i++) {
        if (op[i] != 0) {
            op[i]--; //아래로 내려감
            put_operator(cal(result, arr[index + 1], i), index + 1);
            op[i]++; //위로 다시 올라감
        }
    }
}

int main() {
    int i;

    cin >> N;
    for (i = 0; i < N; i++)
        cin >> arr[i];
    for (i = 0; i < 4; i++)
        cin >> op[i];
    put_operator(arr[0], 0);
    cout << max_num << '\n' << min_num;
}