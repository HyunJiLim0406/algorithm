#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N;

    cin>>N;
    vector<bool> dp(1001, true);
    dp[2] = false;
    for(int i=5;i<=N;i++){
        if(dp[i-1]&&dp[i-3]&&dp[i-4])
            dp[i] = false;
    }
    cout<<((dp[N])?"SK":"CY");
}