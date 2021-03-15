#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	int N, i;

	cin >> N;
	for (i = N; i >= 1; i--)
		cout << i << "\n";
}