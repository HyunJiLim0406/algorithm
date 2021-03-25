#include <iostream>
#include <stack>
using namespace std;

int arr[100001];
char pm[100001];
stack<int> s;

void isStack(int n) { //런타임 에러가 뜨길래 배열들 전역변수로 빼고 else 일 때 바로 return 했던 것 flag로 수정
    int index = 1, pm_cnt = 0;
    bool flag = true;

    for (int i = 0; i < n && flag; i++) {
        if (arr[i] >= index) { //1~n 순서대로 넣으니까 어디까지 넣었는지 index로 체크
            for (int j = index; j <= arr[i]; j++) { //arr[i]가 index보다 크거나 같으면 일단 push
                s.push(j);
                pm[pm_cnt++] = '+';
                index++;
            }
        }
        if (!s.empty() && arr[i] == s.top()) { //empty 체크 중요함. 더 이상 push 못하는 상황에서 pop 가능한지 확인
            s.pop();
            pm[pm_cnt++] = '-';
        }
        else //불가능하면 수열 만들 수 없음
            flag = false;
    }
    if (flag) {
        for (int i = 0; i < pm_cnt; i++)
            cout << pm[i] << '\n';
    }
    else
        cout << "NO\n";
}

int main() {
    int n;

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    isStack(n);
}