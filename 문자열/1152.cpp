#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int count, length, i;
	char word[1000000];

	cin.getline(word, 1000000, '\n'); //���� �����ؼ� �Է¹ޱ�
	length = strlen(word);
	if (word[0] == ' ' && word[length - 1] == ' ') //�������� �����ؼ� �������� ����
		count = -1;
	else if (word[0] == ' ' || word[length - 1] == ' ') //�������� �����ϰų� �������� ����
		count = 0;
	else //���ڷ� �����ؼ� ���ڷ� ����
		count = 1;
	for (i = 0; i < length; i++) {
		if (word[i] == ' ')
			count++;
	}
	cout << count << endl;
}