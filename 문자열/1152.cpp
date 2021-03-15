#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int count, length, i;
	char word[1000000];

	cin.getline(word, 1000000, '\n'); //공백 포함해서 입력받기
	length = strlen(word);
	if (word[0] == ' ' && word[length - 1] == ' ') //공백으로 시작해서 공백으로 끝남
		count = -1;
	else if (word[0] == ' ' || word[length - 1] == ' ') //공백으로 시작하거나 공백으로 끝남
		count = 0;
	else //문자로 시작해서 문자로 끝남
		count = 1;
	for (i = 0; i < length; i++) {
		if (word[i] == ' ')
			count++;
	}
	cout << count << endl;
}