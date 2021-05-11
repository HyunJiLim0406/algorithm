#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N, input[3];
    vector<pair<int, int>> prev, cur; //직전 dp, 현재 dp
    prev.assign(3, make_pair(0, 0));
    cur.assign(3, make_pair(0, 0));

    cin>>N;
    for(int i=0;i<N;i++){
        cin>>input[0]>>input[1]>>input[2];

        cur[0].first = max(prev[0].first, prev[1].first) + input[0]; //0번째의 최댓값
        cur[0].second = min(prev[0].second, prev[1].second) + input[0]; //0번째의 최솟값

        cur[1].first = max(prev[0].first, max(prev[1].first, prev[2].first))+input[1]; //1번째의 최댓값
        cur[1].second = min(prev[0].second, min(prev[1].second, prev[2].second))+input[1]; //1번째의 최솟값

        cur[2].first = max(prev[1].first, prev[2].first) + input[2]; //2번째의 최댓값
        cur[2].second = min(prev[1].second, prev[2].second) + input[2]; //2번째의 최솟값

        prev = cur;
    }
    int max_result = 0;
    int min_result = 1e9;
    for(int i=0;i<3;i++){
        max_result = max(max_result, prev[i].first);
        min_result = min(min_result, prev[i].second);
    }
    cout<<max_result<<' '<<min_result;
}