#include <iostream>
#include <vector>
#include <map>

using namespace std;

string numToString(int num){
    vector<string> numString = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"}; //문자
    string str = to_string(num);
    string ans;
    for(char c:str) //string으로 바꾸기
        ans += numString[c - '0']+" ";
    ans.pop_back(); //마지막 띄어쓰기
    return ans;
}

int main(){
    int m, n;
    map<string, int> ans;

    cin>>m>>n;
    for(int i=m;i<=n;i++)
        ans[numToString(i)] = i;

    int cnt = 0;
    for(auto iter:ans){ //순서대로 출력
        cout<<iter.second<<' ';
        cnt++;
        if(cnt%10==0)
            cout<<'\n';
    }
}