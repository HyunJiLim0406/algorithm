#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int alpha[26], max = 0, max_pos, i_word, i;
	char word[1000000];
	bool flag;
	for (i = 0; i < 26; i++)
		alpha[i] = 0;

	cin >> word;
	int length = strlen(word); //strlen�� for�� �־����� �ð��ʰ�
	for (i = 0; i < length; i++) {
		if (word[i] >= 97) //_strupr_s ����� ��Ÿ�ӿ���
			i_word = (int)word[i] - 97;
		else
			i_word = (int)word[i] - 65;
		alpha[i_word]++;
	}
	for (i = 0; i < 26; i++) {
		if (alpha[i] > max) {
			max = alpha[i];
			max_pos = i;
			flag = false; //max �����ϸ� flag�� �ʱ�ȭ �ؾ���
		}
		else if (alpha[i] == max)
			flag = true; //flag�� true�� ���� ���� ���� ���ڰ� 2�� �̻��̶� ��
	}
	if (flag)
		cout << '?' << '\n';
	else
		cout << (char)(max_pos + 65) << '\n';
}