
#include <iostream>
#include <algorithm>
using namespace std;

struct info {
    int age;
    char name[101];
};

bool cmp(const info& p1, const info& p2) {
    if (p1.age < p2.age) //가입 순이고 stable이면 그냥 나이만 고려하면 됨
        return true;
    else
        return false;
}

int main() {
    int N, i;

    cin >> N;
    info* arr = new info[N];
    for (i = 0; i < N; i++)
        cin >> arr[i].age >> arr[i].name;
    stable_sort(arr, arr + N, cmp); //그냥 sort는 stable 보장하지 않음
    for (i = 0; i < N; i++)
        cout << arr[i].age << ' ' << arr[i].name << '\n';
}