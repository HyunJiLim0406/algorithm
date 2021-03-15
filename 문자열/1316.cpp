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
		for (j = 0; j < 26; j++) //읽었던 알파벳인지 아닌지 체크하는 배열
			checking[j] = -1;
		cin >> word;
		length = strlen(word);
		for (j = 0; j < length; j++) {
			if (checking[word[j] - 97] == -1) { //처음 읽는 알파벳이면
				checking[word[j] - 97] = flag; //정보 입력
				num[j] = flag; //단어를 숫자로 변환하는 num 배열에 저장
				flag++;
			}
			else //이미 읽은 알파벳이면 미리 저장됐던 flag를 그대로 num 배열에 저장
				num[j] = checking[word[j] - 97];
		}
		if (isGroup(num, length)) //그룹 단어가 맞다면 num 배열이 증가하는 형태일 것 ex) happy = 01223
			count++;
	}
	cout << count << endl;
}