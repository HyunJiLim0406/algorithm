#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

struct outfit { //옷 정보 저장
    string name;
    string kind;
};

struct kindCnt { //종류별 옷의 개수 저장
    string kind;
    int cnt;
};
outfit* clothes = new outfit[30];
kindCnt* arr = new kindCnt[30];

int ootd(int n) {
    int cnt = 0;
    int mul = 1;
    bool isExist;

    for (int i = 0; i < n; i++) //개수 초기화
        arr[i].cnt = 0;
    for (int i = 0; i < n; i++) {
        isExist = false;
        for (int j = 0; j < cnt; j++) { //이미 있던 종류 옷이면 개수만 증가하고 break
            if(arr[j].kind.compare(clothes[i].kind)==0){
                arr[j].cnt++;
                isExist = true;
                break;
            }
        }
        if (!isExist) { //새로운 종류의 옷이면 새로 입력
            arr[cnt].kind = clothes[i].kind;
            arr[cnt++].cnt++;
        }
    }
    for (int i = 0; i < cnt; i++) //종류별로 하나의 옷 + 안 입는 선택지이므로 각 개수에 1씩 더해서 곱함
        mul *= (arr[i].cnt + 1);
    return mul - 1; //모든 종류의 옷을 안입는 경우 1개를 뺌
}

int main() {
    int T, n;

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> n;
        for (int j = 0; j < n; j++)
            cin >> clothes[j].name >> clothes[j].kind;
        cout << ootd(n) << '\n';
    }
}