#include <iostream>
using namespace std;

int main() { //반복문으로 풀었는데 시간초과해서 걍 수학으로 품
	int A, B, V, count = 0;

	cin >> A >> B >> V;
	if ((V - B) % (A - B) == 0)
		count = (V - B) / (A - B);
	else
		count = (V - B) / (A - B) + 1;
	cout << count << '\n';
}