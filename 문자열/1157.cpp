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
	int length = strlen(word); //strlen을 for에 넣었더니 시간초과
	for (i = 0; i < length; i++) {
		if (word[i] >= 97) //_strupr_s 썼더니 런타임에러
			i_word = (int)word[i] - 97;
		else
			i_word = (int)word[i] - 65;
		alpha[i_word]++;
	}
	for (i = 0; i < 26; i++) {
		if (alpha[i] > max) {
			max = alpha[i];
			max_pos = i;
			flag = false; //max 갱신하면 flag도 초기화 해야함
		}
		else if (alpha[i] == max)
			flag = true; //flag가 true면 가장 많이 나온 숫자가 2개 이상이란 뜻
	}
	if (flag)
		cout << '?' << '\n';
	else
		cout << (char)(max_pos + 65) << '\n';
}