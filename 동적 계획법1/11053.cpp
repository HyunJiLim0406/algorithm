#include <iostream>
using namespace std;

int arr[1001];
int max_num[1001];

int lis(int num) {
    int point = 1;

    max_num[1] = arr[1]; //초기화
    for (int i = 2; i <= num; i++) {
        for (int j = point; j >= 0; j--) {
            if (arr[i] > max_num[j]) { //만약 큰걸 찾으면
                max_num[j + 1] = arr[i]; //갱신 해주는데
                if (j == point) //만약 그게 시작부터 그랬던 거라면
                    point++; //max_num 배열 인덱스도 증가
                break;
            }
        }
    }
    return point;
}

int main() {
    int N;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];
    cout << lis(N);
}