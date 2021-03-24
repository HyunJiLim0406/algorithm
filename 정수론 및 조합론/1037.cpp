#include <iostream>
#include <algorithm>
using namespace std;

int main() { //가장 작은 약수 * 가장 큰 약수 = 해당 수
    int f_cnt;

    cin >> f_cnt;
    int* f_arr = new int[f_cnt];
    for (int i = 0; i < f_cnt; i++)
        cin >> f_arr[i];
    sort(f_arr, f_arr + f_cnt);
    cout << f_arr[0] * f_arr[f_cnt - 1];
}