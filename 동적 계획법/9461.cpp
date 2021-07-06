#include <iostream>
using namespace std;

long long findP(int num) { //배열은 long long으로 바꿔놓고 리턴을 int로 하고 있었음 에휴
    long long arr[4] = { 0, };
    if (num < 4)
        return 1;
    for (int i = 1; i <= num; i++) {
        if (i < 4)
            arr[i - 1] = 1;
        else {
            arr[3] = arr[1] + arr[0];
            arr[0] = arr[1];
            arr[1] = arr[2];
            arr[2] = arr[3];
        }
    }
    return arr[3];
}

int main() {
    int T;

    cin >> T;
    int* N = new int[T];
    for (int i = 0; i < T; i++)
        cin >> N[i];
    for (int i = 0; i < T; i++) {
        cout << findP(N[i]) << '\n';
    }
}