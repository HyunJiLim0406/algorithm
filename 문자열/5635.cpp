#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct info {
    string name;
    int d, m, y;
};

int main() {
    int n;

    cin >> n;
    vector<string> input(n);
    vector<info> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i].name >> arr[i].d >> arr[i].m >> arr[i].y;
    sort(arr.begin(), arr.end(),
         [](const info &i1, const info &i2) {
             if (i1.y != i2.y)
                 return i1.y < i2.y;
             if (i1.m != i2.m)
                 return i1.m < i2.m;
             return i1.d < i2.d;
         });
    cout << arr[n - 1].name << '\n' << arr[0].name;
}