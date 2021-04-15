#include <iostream>
#include <vector>

using namespace std;

int min_calc = 1000000001;
int max_calc = -1000000001;
int N, op[4], arr[11];
vector<int> num;

int calc() { //계산
    int sum = num[0];

    for (int i = 1; i < N; i++) {
        switch (arr[i - 1]) {
            case 0:
                sum += num[i];
                break;
            case 1:
                sum -= num[i];
                break;
            case 2:
                sum *= num[i];
                break;
            case 3:
                sum /= num[i];
                break;
            default:
                break;
        }
    }
    return sum;
}

void backtracking(int num) {
    if (num == (N - 1)) {
        int result = calc();
        if (result > max_calc) //최댓값 비교
            max_calc = result;
        if (result < min_calc) //최솟값 비교
            min_calc = result;
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (op[i] != 0) {
            op[i]--; //visited 처리
            arr[num] = i;
            backtracking(num + 1);
            op[i]++; //unvisited 처리
        }
    }
}

int main() {
    int input;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> input;
        num.push_back(input);
    }
    for (int i = 0; i < 4; i++)
        cin >> op[i];
    backtracking(0);
    cout << max_calc << '\n' << min_calc;
}