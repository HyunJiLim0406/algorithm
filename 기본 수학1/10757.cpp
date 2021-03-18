#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	string str1, str2;
	vector<int> A, B, C;
	bool isCarry = false; //�޾ƿø� ����

	cin >> str1 >> str2;
	if (str1.size() < str2.size()) //str1(A)�� ���̰� �� �浵��
		swap(str1, str2);

	int dist = str1.size() - str2.size();
	for (int i = 0; i < str1.size(); i++) {
		A.push_back(str1[i] - '0');
		if (i < dist)
			B.push_back(0);
		else
			B.push_back(str2[i - dist] - '0');
	}

	for (int i = str1.size() - 1; i >= 0; i--) {
		int temp;
		if (isCarry) //�޾ƿø��� �־���?
			temp = A[i] + B[i] + 1;
		else
			temp = A[i] + B[i];

		if (temp >= 10) {
			isCarry = true;
			temp -= 10;
		}
		else
			isCarry = false;
		C.push_back(temp);
	}
	if (isCarry) //�������� �޾ƿø��� �־������� �𸣴ϱ�
		C.push_back(1);
	for (int i = C.size() - 1; i >= 0; i--)
		cout << C[i];
}