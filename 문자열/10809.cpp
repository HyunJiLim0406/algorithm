#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int pos[26], i;
	char syntax[100];
	for (i = 0; i < 26; i++)
		pos[i] = -1;

	cin >> syntax;
	for (i = 0; i < strlen(syntax); i++) {
		int i_syntax = (int)syntax[i] - 97;
		if (pos[i_syntax] == -1)
			pos[i_syntax] = i;
	}
	for (i = 0; i < 26; i++)
		cout << pos[i] << ' ';
}