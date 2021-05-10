#include <iostream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    multiset<int> num; //중복 저장
    int T, k, n;
    char cmd;

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> cmd >> n;
            if (cmd == 'I') //삽입
                num.insert(n);
            else if (!num.empty()) {
                if (n == 1) //최댓값 삭제
                    num.erase(--num.end());
                else //최솟값 삭제
                    num.erase(num.begin());
            }
        }
        if (num.empty()) //set이 비어있음
            cout << "EMPTY\n";
        else //최댓값, 최솟값 출력
            cout << *(--num.end()) << ' ' << *num.begin() << '\n';
        num.clear(); //set 초기화
    }
}