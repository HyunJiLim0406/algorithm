#include <iostream>
#include <map>

using namespace std;

int main(){
    int T, N, num;
    string name;

    cin>>T;
    while(T--){
        cin>>N;
        map<int, string, greater<>> m; //내림차순 정렬
        while(N--) {
            cin >> name >> num;
            m[num] = name;
        }
        cout<<m.begin()->second<<'\n'; //맨 앞에 있는 학교 출력
    }
}