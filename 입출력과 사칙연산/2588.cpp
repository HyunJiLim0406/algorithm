#include <iostream>

int main() {
	int a, b, temp, result;
	std::cin >> a >> b;
	result = a * b;
	for (int i = 0; i < 3; i++) {
		temp = b % 10;
		std::cout << temp * a << std::endl;
		b /= 10;
	}
	std::cout << result << std::endl;
	return 0;
}