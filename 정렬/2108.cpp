#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, count[8001] = { 0, }, max = -4001, min = 4001, i;
    double sum = 0.0;
    bool isOne;

    cin >> N;
    int* arr = new int[N];
    for (i = 0; i < N; i++) {
        cin >> arr[i];
        sum += arr[i]; //평균용 합 구하기
        if (arr[i] > max) //최댓값 갱신
            max = arr[i];
        if (arr[i] < min) //최솟값 갱신
            min = arr[i];
        count[arr[i] + 4000]++; //음수도 저장하려고 4000 더한 값에 ++ 해줌
    }
    sort(arr, arr + N); //중앙값용 정렬
    int mode_num, mode_count = 0; //최빈값용 변수
    for (i = 0; i < 8001; i++) {
        if (count[i] == mode_count) //유일한 최빈값인지 체크
            isOne = false;
        else if (count[i] > mode_count) {
            mode_count = count[i];
            mode_num = i - 4000; //원래 4000 더해서 받았으니까 4000 뺌. 만약 유일한 최빈값이면 얠 바로 출력
            isOne = true;
        }
    }
    if (!isOne) { //최빈값이 유일하지 않다면
        for (i = mode_num + 4001; i < 8001; i++) { //받아놓은 mode_num이 첫번째 최빈값일테니까 그 다음부터 체크하면 됨
            if (count[i] == mode_count) {
                mode_num = i - 4000;
                break;
            }
        }
    }
    cout << fixed;
    cout.precision(0); //이게 반올림도 해준다고 함
    cout << sum / N << '\n' << arr[N / 2] << '\n' << mode_num << '\n' << max - min << '\n';
}