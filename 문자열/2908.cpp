#include <iostream>
#include <sstream>
using namespace std;

int swap(char* num) {
	int s_num;
	char temp;

	temp = num[2];
	num[2] = num[0];
	num[0] = temp; //swap ��
	string a(num);
	stringstream str(a);
	str >> s_num; //char �迭�� int�� �ٲ��ִ� ���

	return s_num;
}

int main() {
	int n_A, n_B;
	char A[4], B[4];

	cin >> A >> B;
	n_A = swap(A);
	n_B = swap(B);
	if (n_A > n_B)
		cout << n_A << endl;
	else
		cout << n_B << endl;
}