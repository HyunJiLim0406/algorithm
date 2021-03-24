#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long num_arr[100];
vector<int> v;

int gcd(int a, int b) { //유클리드 호제법(?)으로 최대공약수 구함
    int temp, n;

    if (a < b) {
        temp = a;
        a = b;
        b = temp;
    }
    while (b != 0) {
        n = a % b;
        a = b;
        b = n;
    }
    return a;
}

void findM(int N) { //제일 앞에 두개 빼고 그 뒤부터 인접한 애들끼리 빼서 최대공약수를 구하면 된다는데 이유는 모름
    long long g = num_arr[1] - num_arr[0];

    for (int i = 2; i < N; i++)
        g = gcd(g, num_arr[i] - num_arr[i - 1]);
    for (int i = 2; i * i <= g; i++) { //약수를 구하는 빠른 방법
        if (g % i == 0) {
            v.push_back(i);
            v.push_back(g / i);
        }
    }
    v.push_back(g);
}

int main() { //수학적 지식이 많이 필요한 듯 함
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> num_arr[i];
    sort(num_arr, num_arr + N);
    findM(N);
    sort(v.begin(), v.end()); //정렬
    v.erase(unique(v.begin(), v.end()), v.end()); //중복제거(정렬하고 해야한다고 함)
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << ' ';
}