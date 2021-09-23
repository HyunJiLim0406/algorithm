#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<char> arr;

void fillArr(int num, int pos) {
    if (num == 1) { //길이가 1
        arr[pos] = '-';
        return;
    }
    int size = num / 3; //3등분
    fillArr(size, pos);
    fillArr(size, pos + (size * 2));
}

int main() {
    int input;

    while (cin >> input) {
        int size = pow(3, input); //전체 길이
        arr.assign(size, ' ');
        fillArr(size, 0);
        for (int i = 0; i < size; i++)
            cout << arr[i];
        cout << '\n';
    }
}