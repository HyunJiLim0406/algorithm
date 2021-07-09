#include <iostream>

using namespace std;

int day1, day2;

void recurCnt(int cur){ //첫날, 둘째날 준 떡으로 전체 개수 치환
    if(cur==1)
        day1++;
    else if(cur==2)
        day2++;
    else{
        recurCnt(cur-1);
        recurCnt(cur-2);
    }
}

int main(){
    int D, K;

    cin>>D>>K;
    recurCnt(D);
    int a = 1, b = 1;
    while(true){ //a를 늘리면서 b 찾기
        int num = K-a*day1;
        if(num%day2==0){
            b = num/day2;
            break;
        }
        a++;
    }
    cout<<a<<'\n'<<b;
}