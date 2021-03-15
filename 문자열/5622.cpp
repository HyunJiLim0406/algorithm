#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char word[20];
	int dist = 0, length;

	cin >> word;
	length = strlen(word);
	for (int i = 0; i < length; i++) {
		switch (word[i]) {
		case 'A':
		case 'B':
		case 'C':
			dist += 3;
			break;
		case 'D':
		case 'E':
		case 'F':
			dist += 4;
			break;
		case 'G':
		case 'H':
		case 'I':
			dist += 5;
			break;
		case 'J':
		case 'K':
		case 'L':
			dist += 6;
			break;
		case 'M':
		case 'N':
		case 'O':
			dist += 7;
			break;
		case 'P':
		case 'Q':
		case 'R':
		case 'S':
			dist += 8;
			break;
		case 'T':
		case 'U':
		case 'V':
			dist += 9;
			break;
		case 'W':
		case 'X':
		case 'Y':
		case 'Z':
			dist += 10;
			break;
		default:
			cout << "wrong" << endl;
			break;
		}
	}
	cout << dist << endl;
}