#include <iostream>

using namespace std;

int main() {
    int n, cnt = 0;

    cin >> n;
    cnt += n / 5; //5원 최대한 쓰기
    n %= 5; //나머지
    while (n % 2 != 0 && cnt) { //나머지가 2로 나누어 떨어질때까지 5원 반납
        cnt--;
        n += 5;
    }
    if (n % 2 != 0) //거스름돈 반환 불가
        cout << -1;
    else //최종 거스름돈 갯수
        cout << cnt + (n / 2);
}