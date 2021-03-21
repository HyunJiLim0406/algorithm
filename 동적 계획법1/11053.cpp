#include <iostream>
using namespace std;

int arr[1001];
int max_num[1001];

int lis(int num) {
    int point = 0;
    bool isFirst; //해당 노드의 길이가 1인지 확인

    max_num[0] = arr[0]; //초기화
    for (int i = 1; i < num; i++) {
        isFirst = true;
        for (int j = point; j >= 0; j--) {
            if (arr[i] > max_num[j]) { //만약 큰걸 찾으면
                isFirst = false; //제일 작은게 아니고
                max_num[j + 1] = arr[i]; //갱신 해주는데
                if (j == point) //만약 그게 시작부터 그랬던 거라면
                    point++; //max_num 배열 인덱스도 증가
                break;
            }
        }
        if (isFirst) //제일 작은거라면 max_num[0] 갱신
            max_num[0] = arr[i];
    }
    return point + 1;
}

int main() {
    int N;

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    cout << lis(N);
}