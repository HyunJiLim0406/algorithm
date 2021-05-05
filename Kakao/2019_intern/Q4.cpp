#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
typedef long long ll;
unordered_map<ll, ll> node;

ll findEmpty(ll num){
    if(!node[num]) //부모가 없음 = 비어있음
        return num;
    return node[num] = findEmpty(node[num]); //부모 찾으면서 새로운 값으로 갱신
}

vector<ll> solution(ll k, vector<ll> room_number) {
    vector<ll> answer;
    for(int i=0;i<room_number.size();i++){
        ll room = findEmpty(room_number[i]); //원하는 방이 비어있다면 바로 반환, 아니라면 부모 조회하며 빈 방 찾기
        answer.push_back(room);
        node[room] = room+1; //비어있던 방에 부모 할당
    }
    return answer;
}

int main(){
    vector<ll> v = solution(10, {1, 3, 4, 1, 3, 1});
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<' ';
}