#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int power[20][20], N;

int calcPower(vector<int> v){ //각 팀의 power 계산
    int result = 0;

    for(int i=0;i<v.size();i++){
        for(int j=0;j<v.size();j++)
            result += power[v[i]][v[j]];
    }
    return result;
}

int splitTeam(int num) {
    vector<int> start, link;

    for (int i = 0; i < N; i++) {
        if ((num & (1 << i)) == 0) //해당 비트 0이면 링크팀
            link.push_back(i);
        else //해당 비트 1이면 스타트팀
            start.push_back(i);
    }
    return abs(calcPower(link) - calcPower(start)); //차이
}

int main() {
    int min_pow = -1;

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cin >> power[i][j];
    }
    for (int i = 1; i < ((1 << N) - 1); i++) { //N=4라면 0001~1110
        if (min_pow == -1) //최솟값 갱신
            min_pow = splitTeam(i);
        min_pow = min(min_pow, splitTeam(i));
    }
    cout << min_pow;
}