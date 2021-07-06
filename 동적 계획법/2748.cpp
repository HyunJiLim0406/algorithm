#include <iostream>
using namespace std;

long long fibo(int num) {
    long long fibo_arr[91] = { 0, }; //int로 하면 스택오버플로우
    for (int i = 0; i <= num; i++) {
        if (i < 2)
            fibo_arr[i] = i;
        else { //동적계획법
            fibo_arr[i] = fibo_arr[i - 1] + fibo_arr[i - 2];
        }
    }
    return fibo_arr[num];
}

int main() {
    int n;

    cin >> n;
    cout << fibo(n);
}