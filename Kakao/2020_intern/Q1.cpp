#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>

using namespace std;

map<char, pair<int, int>> pad;

int dist(char source, char dest) { //행, 열 차이의 절댓값의 합
    pair<int, int> s_pos = pad[source];
    pair<int, int> d_pos = pad[dest];
    return (abs(s_pos.first - d_pos.first) + abs(s_pos.second - d_pos.second));
}

string moveHand(vector<int> numbers, string hand) {
    char l_pos = '*'; //왼손의 현위치
    char r_pos = '#'; //오른손의 현위치
    string result = "";

    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] % 3 == 1) { //1, 4, 7
            result += "L";
            l_pos = numbers[i] + '0';
        } else if ((numbers[i] != 0) && (numbers[i] % 3 == 0)) { //3, 6, 9
            result += "R";
            r_pos = numbers[i] + '0';
        } else {
            int l_dist = dist(l_pos, numbers[i] + '0'); //왼손 거리
            int r_dist = dist(r_pos, numbers[i] + '0'); //오른손 거리
            if ((l_dist < r_dist) || ((l_dist == r_dist) && (hand.compare("left") == 0))) { //왼손 거리 짧거나, 왼손잡이
                result += "L";
                l_pos = numbers[i] + '0';
            } else if ((l_dist > r_dist) || ((l_dist == r_dist) && (hand.compare("right") == 0))) { //오른손 거리 짧거나, 오른손잡이
                result += "R";
                r_pos = numbers[i] + '0';
            }
        }
    }
    return result;
}

string solution(vector<int> numbers, string hand) {
    for (int i = 0; i < 9; i++)
        pad[(i + 1) + '0'] = make_pair(i / 3, i % 3);
    pad['*'] = make_pair(3, 0);
    pad['0'] = make_pair(3, 1);
    pad['#'] = make_pair(3, 2);
    string answer = moveHand(numbers, hand);
    return answer;
}

int main(){
    cout<<solution({1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5}, "right")<<'\n';
    cout<<solution({7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2}, "left")<<'\n';
    cout<<solution({1, 2, 3, 4, 5, 6, 7, 8, 9, 0}, "right")<<'\n';
}