#include <iostream>
using namespace std;

int main() { //�ݺ������� Ǯ���µ� �ð��ʰ��ؼ� �� �������� ǰ
	int A, B, V, count = 0;

	cin >> A >> B >> V;
	if ((V - B) % (A - B) == 0)
		count = (V - B) / (A - B);
	else
		count = (V - B) / (A - B) + 1;
	cout << count << '\n';
}