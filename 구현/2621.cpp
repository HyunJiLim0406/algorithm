#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct info {
    char color;
    int num;
};

int cond1(vector<info> &arr) {
    char color = arr[0].color;
    int num = arr[0].num;
    for (int i = 1; i < 5; i++) {
        if (arr[i].color != color || arr[i].num != num + i)
            return 0;
    }
    return arr[4].num + 900;
}

int cond2(vector<info> &arr) {
    int num = arr[1].num;
    for (int i = 2; i < 4; i++) {
        if (arr[i].num != num)
            return 0;
    }
    if (num == arr[0].num || num == arr[4].num)
        return num + 800;
    return 0;
}

int cond3(vector<info> &arr) {
    if (arr[0].num == arr[1].num && arr[3].num == arr[4].num) {
        if (arr[1].num == arr[2].num)
            return arr[0].num * 10 + arr[4].num + 700;
        if (arr[2].num == arr[3].num)
            return arr[4].num * 10 + arr[0].num + 700;
    }
    return 0;
}

int cond4(vector<info> &arr) {
    char color = arr[0].color;
    for (int i = 1; i < 5; i++) {
        if (arr[i].color != color)
            return 0;
    }
    return arr[4].num + 600;
}

int cond5(vector<info> &arr) {
    int num = arr[0].num;
    for (int i = 1; i < 5; i++) {
        if (arr[i].num != num + i)
            return 0;
    }
    return arr[4].num + 500;
}

int cond6(vector<info> &arr) {
    int cnt = 1, num = arr[0].num;
    for (int i = 1; i < 5; i++) {
        if (arr[i].num == num)
            cnt++;
        else {
            num = arr[i].num;
            cnt = 1;
        }
        if (cnt == 3)
            return num + 400;
    }
    return 0;
}

int cond7(vector<info> &arr) {
    int cnt = 1, n = arr[0].num;
    vector<int> num;
    for (int i = 1; i < 5; i++) {
        if (arr[i].num == n)
            cnt++;
        else {
            n = arr[i].num;
            cnt = 1;
        }
        if (cnt == 2)
            num.push_back(n);
    }
    if (num.size() == 2)
        return max(num[0], num[1]) * 10 + min(num[0], num[1]) + 300;
    return 0;
}

int cond8(vector<info> &arr) {
    int cnt = 1, num = arr[0].num;
    for (int i = 1; i < 5; i++) {
        if (arr[i].num == num)
            cnt++;
        else {
            num = arr[i].num;
            cnt = 1;
        }
        if (cnt == 2)
            return num + 200;
    }
    return 0;
}

int cond9(vector<info> &arr) {
    return arr[4].num + 100;
}

int main() {
    vector<info> arr(5);
    for (int i = 0; i < 5; i++)
        cin >> arr[i].color >> arr[i].num;
    sort(arr.begin(), arr.end(),
         [](const info &i1, const info &i2) {
             return i1.num < i2.num;
         });

    int result = 0;
    result = max(result, cond1(arr));
    result = max(result, cond2(arr));
    result = max(result, cond3(arr));
    result = max(result, cond4(arr));
    result = max(result, cond5(arr));
    result = max(result, cond6(arr));
    result = max(result, cond7(arr));
    result = max(result, cond8(arr));
    result = max(result, cond9(arr));
    cout << result;
}