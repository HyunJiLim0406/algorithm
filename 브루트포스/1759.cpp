#include <iostream>
#include <algorithm>

using namespace std;

int L, C;
char input[15], arr[15];

bool isPromising() {
    int vowel = 0;
    for (int i = 0; i < L; i++) {
        if ((arr[i] == 'a') || (arr[i] == 'e') || (arr[i] == 'i') || (arr[i] == 'o') || (arr[i] == 'u')) //모음 개수 확인
            vowel++;
    }
    if ((vowel >= 1) && ((L - vowel) >= 2)) //자음, 모음 개수 확인
        return true;
    return false;
}

void backtracking(int idx, int num) {
    if (num == L) {
        if (isPromising()) { //자음, 모음 개수 확인 후 출력
            for (int i = 0; i < L; i++)
                cout << arr[i];
            cout << '\n';
        }
        return;
    }
    for (int i = idx + 1; i < C; i++) { //오름차순으로 탐색하기 위해
        arr[num] = input[i];
        backtracking(i, num + 1);
    }
}

int main() {
    cin >> L >> C;
    for (int i = 0; i < C; i++)
        cin >> input[i];
    sort(input, input + C); //정렬
    backtracking(-1, 0);
}