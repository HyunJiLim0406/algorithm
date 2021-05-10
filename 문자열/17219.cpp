#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    string site, pw;
    map<string, string> info;

    cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>site>>pw;
        info[site] = pw;
    }
    for(int i=0;i<M;i++){
        cin>>site;
        cout<<info[site]<<'\n';
    }
}