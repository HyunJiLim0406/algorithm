#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue<int, vector<int>, greater<int>> pq; //greater면 min heap
    int N, x;

    cin>>N;
    for(int i=0;i<N;i++){
        cin>>x;
        if(x==0){
            if (pq.empty())
                cout<<0<<'\n';
            else{
                cout<<pq.top()<<'\n';
                pq.pop();
            }
        }
        else
            pq.push(x);
    }
}