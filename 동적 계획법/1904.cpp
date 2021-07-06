#include <iostream>
using namespace std;

/*처음엔 중복 조합으로 풀었으나 계속 런타임 에러 알고보니 이거 피보나치 문제였음*/
/*
long long combination(int a, int b) { //중복 조합의 흔적
	long long x = 1, y = 1;
	if ((a / 2) < b) //5C3 이런거일 수도 있으니까 체크
		b = a - b;
	for (int i = 0; i < b; i++) {
		x *= a;
		a--;
	}
	for (int i = b; i >= 1; i--) {
		y *= i;
	}
	return (x / y);
}
*/

int tile(int num) {
    int arr[3]; //이걸 다 저장하면 오버플로우니까 3개만 저장
    if (num < 3) //1, 2면 걍 리턴
        return num;
    for (int i = 1; i <= num; i++) {
        if (i == 1)
            arr[0] = 1;
        else if (i == 2)
            arr[1] = 2;
        else {
            arr[2] = (arr[0] + arr[1]) % 15746; //나머지로 저장
            arr[0] = arr[1];
            arr[1] = arr[2];
        }
    }
    /* 조합의 흔적22
    long long cnt = 1;
    int num_of_ztile = num / 2;
    for (int i = 1; i <= num_of_ztile; i++) {
        cnt = (cnt + combination(num - i, i)) % 15746;
    }
    */
    return arr[2];
}

int main() {
    int N;

    cin >> N;
    cout << tile(N);
}