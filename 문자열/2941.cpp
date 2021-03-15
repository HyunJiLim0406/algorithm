#include <iostream>
#include <cstring>
using namespace std;

int wordJump(char* word, int pos) {
	int jump = 1;

	if (word[pos] == 'c') {
		if (word[pos + 1] == '=' || word[pos + 1] == '-')
			jump = 2;
	}
	else if (word[pos] == 'd') {
		if (word[pos + 1] == 'z' && word[pos + 2] == '=')
			jump = 3;
		else if (word[pos + 1] == '-')
			jump = 2;
	}
	else if (word[pos] == 'l' || word[pos] == 'n') {
		if (word[pos + 1] == 'j')
			jump = 2;
	}
	else if (word[pos] == 's' || word[pos] == 'z') {
		if (word[pos + 1] == '=')
			jump = 2;
	}

	return jump;
}

int main() {
	char word[100];
	int count = 0, i = 0;

	cin >> word;
	int length = strlen(word);
	while (i < length) {
		int next_i = wordJump(word, i);
		count++;
		i += next_i;
	}
	cout << count << endl;
}