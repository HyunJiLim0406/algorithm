#include <iostream>
#include <string>
#include <vector>

using namespace std;

string one(string str){
    for(int i=0;i<str.size();i++){
        if((str[i]>='A')&&(str[i]<='Z'))
            str[i] = tolower(str[i]);
    }
    return str;
}

string twoThree(string str){
    string res = "";
    bool isDot = false;
    for(int i=0;i<str.size();i++){
        if(((str[i]>='a')&&(str[i]<='z'))||((str[i]>='0')&&(str[i]<='9'))||(str[i]=='-')||(str[i]=='_')){
            isDot = false;
            res+=str[i];
        }
        else if((str[i]=='.')&&!isDot){
            isDot = true;
            res+=str[i];
        }
    }
    return res;
}

string four(string str){
    if(str[0]=='.')
        str.erase(str.begin());
    if(str[str.size()-1]=='.')
        str.erase(str.begin()+str.size()-1);
    return str;
}

string five(string str){
    if(str.size()==0)
        str+="a";
    return str;
}

string six(string str){
    if(str.size()>=16)
        str.erase(15);
    return str;
}

string seven(string str){
    if(str.size()<=2){
        char concat = str[str.size()-1];
        while(str.size()!=3)
            str+=concat;
    }
    return str;
}

string solution(string new_id) {
    string answer = new_id;
    answer = one(answer);
    answer = twoThree(answer);
    answer = four(answer);
    answer = five(answer);
    answer = six(answer);
    answer = four(answer);
    answer = seven(answer);
    return answer;
}

int main(){
    cout<<solution("...!@BaT#*..y.abcdefghijklm")<<'\n';
    cout<<solution("z-+.^.")<<'\n';
    cout<<solution("=.=")<<'\n';
    cout<<solution("123_.def")<<'\n';
    cout<<solution("abcdefghijklmn.p")<<'\n';
}