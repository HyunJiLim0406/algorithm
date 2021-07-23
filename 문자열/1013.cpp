#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main(){
    int T;
    string input;

    cin>>T;
    while(T--){
        cin>>input;
        regex re("(100+1+|01)+");
        cout<<(regex_match(input, re)?"YES":"NO")<<'\n';
    }
}