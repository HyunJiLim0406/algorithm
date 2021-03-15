#include <iostream>
#include <cstring>
using namespace std;

bool isGroup(int* num, int length) {
	for (int i = 0; i < length - 1; i++) {
		if (num[i + 1] < num[i])
			return false;
	}
	return true;
}

int main() {
	int N, count = 0, flag, length, i, j, num[100], checking[26];
	char word[101];

	cin >> N;
	for (i = 0; i < N; i++) {
		flag = 0;
		for (j = 0; j < 26; j++) //�о��� ���ĺ����� �ƴ��� üũ�ϴ� �迭
			checking[j] = -1;
		cin >> word;
		length = strlen(word);
		for (j = 0; j < length; j++) {
			if (checking[word[j] - 97] == -1) { //ó�� �д� ���ĺ��̸�
				checking[word[j] - 97] = flag; //���� �Է�
				num[j] = flag; //�ܾ ���ڷ� ��ȯ�ϴ� num �迭�� ����
				flag++;
			}
			else //�̹� ���� ���ĺ��̸� �̸� ����ƴ� flag�� �״�� num �迭�� ����
				num[j] = checking[word[j] - 97];
		}
		if (isGroup(num, length)) //�׷� �ܾ �´ٸ� num �迭�� �����ϴ� ������ �� ex) happy = 01223
			count++;
	}
	cout << count << endl;
}