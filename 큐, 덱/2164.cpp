#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue <int> q;
    int N;

    cin >> N;
    for (int i = 1; i <= N; i++)
        q.push(i);
    while (q.size() != 1) { //한 장만 남으면 종료
        q.pop(); //첫 장 제거
        int tmp = q.front(); //그 다음장 저장해두고
        q.pop(); //제거
        q.push(tmp); //맨 뒤로 다시 넣어줌
    }
    cout << q.front();
}