#include <iostream>
#include <string>

using namespace std;

char cmp[10][10];
int arr[10], N;
bool isFound;

bool isPromising(int cnt, int sum) {
    for (int i = 0; i <= cnt; i++) { //cmp[0][cnt]~cmp[cnt][cnt]까지 열 1개 확인
        if ((cmp[i][cnt] == '+') && (sum <= 0)) //+인데 0보다 작거나 같으면 안됨
            return false;
        else if ((cmp[i][cnt] == '-') && (sum >= 0)) //-인데 0보다 크거나 같으면 안됨
            return false;
        else if ((cmp[i][cnt] == '0') && (sum != 0)) //0인데 0이 아니면 안됨
            return false;
        sum -= arr[i];
    }
    return true;
}

void backtracking(int cnt, int sum) {
    if (cnt == N) { //제일 먼저 찾은 arr
        isFound = true;
        return;
    }
    for (int i = -10; i <= 10 && !isFound; i++) {
        arr[cnt] = i; //arr 배열에 i 입력
        if (isPromising(cnt, sum + i)) //(sum+i)=(arr[0]부터 arr[cnt]까지 더한 값)
            backtracking(cnt + 1, sum + i);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string input;

    cin >> N >> input;
    int pos = 0;
    for (int i = 0; i < N; i++) { //string 입력을 행렬로 정리
        for (int j = i; j < N; j++)
            cmp[i][j] = input[pos++];
    }
    backtracking(0, 0);
    for (int i = 0; i < N; i++)
        cout << arr[i] << ' ';
}