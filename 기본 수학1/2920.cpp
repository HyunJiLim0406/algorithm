#include <iostream>

using namespace std;

int main(){
    int input[8];
    for(int i=0;i<8;i++)
        cin>>input[i];
    if(input[0]==1){
        for(int i=1;i<8;i++){
            if(input[i]!=(i+1)){
                cout<<"mixed\n";
                return 0;
            }
        }
        cout<<"ascending\n";
    }
    else if(input[0]==8){
        for(int i=1;i<8;i++){
            if(input[i]!=(8-i)){
                cout<<"mixed\n";
                return 0;
            }
        }
        cout<<"descending\n";
    }
    else
        cout<<"mixed\n";
}